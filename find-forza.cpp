#include <winrt/base.h>

#include <winrt/Windows.ApplicationModel.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Management.Deployment.h>

#include <algorithm>
#include <format>
#include <iostream>
#include <map>
#include <vector>

using std::cout;

struct PackageInfo
{
	winrt::hstring displayName;
	winrt::hstring id;
	winrt::hstring installedPath;
};

void PrintPackage(winrt::Windows::ApplicationModel::Package package)
{
	// Some displaynames contain unicode characters, like the trademark symbol after 'Thunderbolt'.
	// Using `wcout` and the wide strings seems to occassionally get confused by this, so this
	// program is built with the UTF-8 code page forced in the manifest, and uses the UTF-8 conve
	// 		// program is built with the UTF-8 code page forced in the manifest, and uses the UTF-8 conversions
	cout << std::format("{}:\n", winrt::to_string(package.Id().FullName()));
	cout << std::format("\tDisplayName:\t{}\n", winrt::to_string(package.DisplayName()));
	cout << std::format("\tInstalledPath:\t{}\n", winrt::to_string(package.InstalledPath()));
}

int main()
{
	winrt::init_apartment();

	winrt::Windows::Management::Deployment::PackageManager pm;

	std::vector<winrt::Windows::ApplicationModel::Package> packages;

	// Convert the Windows::Foundation::Collections::IIterable to an std::vector...
	for (auto package : pm.FindPackagesForUser(L""))
	{
		packages.push_back(package);
	}
	// ... so we can sort it.
	std::ranges::sort(packages, {}, [](auto &pkg)
					  { return pkg.Id().FullName(); });

	for (auto package : packages)
	{
		if (package.IsFramework())
		{
			continue;
		}
		PrintPackage(package);
	}

	const std::map<const char *, const wchar_t *> wanted{
		{"Forza Horizon 5", L"Microsoft.624F8B84B80_3.629.845.0_x64__8wekyb3d8bbwe"},
		{"Forza Motorsport 7", L"Microsoft.ApolloBaseGame_1.174.4791.2_x64__8wekyb3d8bbwe"},
	};

	for (const auto [label, id] : wanted)
	{
		cout << std::format("----------\n{}\n----------\n", label);
		// found the ID by searching the previous output for "Forza" in the DisplayName
		auto it = std::ranges::find(packages, id, [](auto pkg)
									{ return pkg.Id().FullName(); });
		if (it == packages.end())
		{
			cout << "Not found.\n";
		}
		else
		{
			PrintPackage(*it);
		}
	}

	cout << std::flush;
	return 0;
}