# README

```shell
mkdir conanexample
conan new conanexample/1.0 -s -t
conan create . wr/testing
```

通过deb包安装conan带来的问题
```shell
cmake: /opt/conan/liblzma.so.5: version `XZ_5.2' not found (required by /lib/x86_64-linux-gnu/libarchive.so.13)
```

通过pip安装没有问题
https://github.com/conan-io/conan/issues/11590

## conan new
run test
## conan 添加库
https://docs.conan.io/en/latest/reference/conanfile/dependencies.html
clion conan

所以一个项目中是不允许conanfile.txt和conanfile.py共存的(都来是包定义，到底听谁的呢)，执行conan命令会报错。

conanfile.py增加库
```python
    requires = "gtest/1.11.0", "cjson/1.7.12"

    def generate(self):
        gtest = self.dependencies["gtest"]
        # access to members
        gtest.ref.version
        gtest.ref.revision # recipe revision
        gtest.options
        gtest.settings
```

在conan install 阶段下载库的，下载的是头文件和库文件

conanfile.py

https://docs.conan.io/en/latest/introduction.html

```shell
conan -h
Consumer commands
  install    Installs the requirements specified in a recipe (conanfile.py or conanfile.txt).
  config     Manages Conan configuration.
  get        Gets a file or list a directory of a given reference or package.
  info       Gets information about the dependency graph of a recipe.
  search     Searches package recipes and binaries in the local cache or a remote. Unless a
             remote is specified only the local cache is searched.
Creator commands
  new        Creates a new package recipe template with a 'conanfile.py' and optionally,
             'test_package' testing files.
  create     Builds a binary package for a recipe (conanfile.py).
  upload     Uploads a recipe and binary packages to a remote.
  export     Copies the recipe (conanfile.py & associated files) to your local cache.
  export-pkg Exports a recipe, then creates a package from local source and build folders.
  test       Tests a package consuming it from a conanfile.py with a test() method.
Package development commands
  source     Calls your local conanfile.py 'source()' method.
  build      Calls your local conanfile.py 'build()' method.
  package    Calls your local conanfile.py 'package()' method.
  editable   Manages editable packages (packages that reside in the user workspace, but are
             consumed as if they were in the cache).
  workspace  Manages a workspace (a set of packages consumed from the user workspace that
             belongs to the same project).
Misc commands
  profile    Lists profiles in the '.conan/profiles' folder, or shows profile details.
  remote     Manages the remote list and the package recipes associated with a remote.
  user       Authenticates against a remote with user/pass, caching the auth token.
  imports    Calls your local conanfile.py or conanfile.txt 'imports' method.
  copy       Copies conan recipes and packages to another user/channel.
  remove     Removes packages or binaries matching pattern from local cache or remote.
  alias      Creates and exports an 'alias package recipe'.
  download   Downloads recipe and binaries to the local cache, without using settings.
  inspect    Displays conanfile attributes, like name, version, and options. Works locally,
             in local cache and remote.
  help       Shows help for a specific command.
  lock       Generates and manipulates lock files.
  frogarian  Conan The Frogarian

Conan commands. Type "conan <command> -h" for help
```



##### conan info
```shell
conan info .
conanfile.py (conanexample/1.0)
    ID: 50a5030bbbb13ae56bc4be41915ecd48549cb895
    BuildID: None
    Context: host
    URL: <Package recipe repository url here, for issues about the package>
    License: <Put the package license here>
    Author: <Put your name here> <And your email here>
    Description: <Description of Conanexample here>
    Topics: <Put some tag here>, <here>, <and here>
    Provides: conanexample
```


#### conan inspect

```shell
conan inspect .
name: conanexample
version: 1.0
url: <Package recipe rconan inspect .
name: conanexample
version: 1.0
url: <Package recipe repository url here, for issues about the package>
homepage: None
license: <Put the package license here>
author: <Put your name here> <And your email here>
description: <Description of Conanexample here>
topics: ('<Put some tag here>', '<here>', '<and here>')
generators: cmake
exports: None
exports_sources: src/*
short_paths: False
apply_env: True
build_policy: None
revision_mode: hash
settings: ('os', 'compiler', 'build_type', 'arch')
options:
    fPIC: [True, False]
    shared: [True, False]
default_options:
    fPIC: True
    shared: False
deprecated: None
apply_env: True
build_policy: None
revision_mode: hash
settings: ('os', 'compiler', 'build_type', 'arch')
options:
    fPIC: [True, False]
    shared: [True, False]
default_options:
    fPIC: True
    shared: False
deprecated: None
```

### conan如何解决依赖版本冲突

报错信息
```shell
WARN: folly/2022.01.31.00: requirement openssl/1.1.1q overridden by your conanfile to openssl/1.1.1s 
WARN: boost/1.78.0: requirement zlib/1.2.13 overridden by folly/2022.01.31.00 to zlib/1.2.12 
ERROR: Conflict in grpc/1.48.0:
    'grpc/1.48.0' requires 'zlib/1.2.13' while 'boost/1.78.0' requires 'zlib/1.2.12'.
    To fix this conflict you need to override the package 'zlib' in your root package.
```

解决办法
在conanfile.py中定义库的版本

##  windows编译
cd build
conan install ../ --build=missing
cd ../
cmake --preset conan-default
cd build
cmake --build .
