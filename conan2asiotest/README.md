# README

https://think-async.com/Asio/asio-1.28.0/doc/asio/examples/cpp14_examples.html

要生成 Conan 2.0.6 的 `conan_provider.cmake` 文件，您可以按照以下步骤操作：

1. 确保已安装 Conan 2.0.6 或更新版本。您可以在命令行中运行 `conan --version` 来检查安装的版本。

2. 打开命令行界面，并导航到您要生成 `conan_provider.cmake` 文件的目录。

3. 运行以下命令来生成 `conan_provider.cmake` 文件：

   ```shell
   conan install <package_reference> --install-folder=<install_folder>
   ```

   在上面的命令中，将 `<package_reference>` 替换为您想要安装的任何包的引用。如果您只是想生成 `conan_provider.cmake` 文件而不进行实际包安装，您可以将 `<package_reference>` 替换为您选择的任何包的引用。 `<install_folder>` 是一个可选的参数，用于指定安装文件夹的路径。如果未提供 `<install_folder>`，则 `conan_provider.cmake` 文件将默认生成到当前目录。

   例如，要生成 `conan_provider.cmake` 文件并安装 OpenSSL 包，可以运行以下命令：

   ```shell
   conan install OpenSSL/1.1.1k@ --install-folder=.
   ```

   这将生成 `conan_provider.cmake` 文件并将 OpenSSL 包安装到当前目录。

4. 完成上述步骤后，您应该在指定的 `<install_folder>` 或当前目录中找到生成的 `conan_provider.cmake` 文件。

请注意，上述步骤假定您已正确安装并配置了 Conan，并且已设置适当的 Conan 远程存储库。如果您尚未安装 Conan，可以从 Conan 官方网站（https://conan.io）下载并按照说明进行安装。

希望这可以帮助您生成 Conan 2.0.6 的 `conan_provider.cmake` 文件。如有需要，请根据您的具体情况进行适当调整。


D:\dev_tools\Conan\conan\conan.exe install asio/1.28.0 --install-folder=.
