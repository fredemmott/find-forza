#include <winrt/base.h>

#include <winrt/Windows.ApplicationModel.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Management.Deployment.h>

#include <algorithm>
#include <format>
#include <iostream>
#include <vector>

using std::wcout, std::endl;

struct PackageInfo
{
	winrt::hstring displayName;
	winrt::hstring id;
	winrt::hstring installedPath;
};

int main()
{
	winrt::init_apartment();

	winrt::Windows::Management::Deployment::PackageManager pm;

	std::vector<winrt::Windows::ApplicationModel::Package> packages;

	// Convert the Windows::Foundation::Collections::IIterable to an std::vector...
	for (auto package : pm.FindPackagesForUser({}))
	{
		packages.push_back(package);
	}
	// ... so we can sort it.
	std::ranges::sort(packages, {}, [](auto &pkg)
					  { return pkg.Id().FullName(); });

	for (auto package : packages)
	{
		wcout
			<< std::format(L"{}:", package.Id().FullName()) << endl
			<< std::format(L"\tDisplayName:\t{}", package.DisplayName()) << endl
			<< std::format(L"\tInstalledPath:\t{}", package.InstalledPath()) << endl;
	}

	return 0;
}