# 修复记录：conan2 generate() PermissionError（2026-11-08）

## 失败信息
- 仓库：wiseism/conan2prjs
- Workflow：conan2 build
- 失败 run：[41938302601](https://github.com/wiseism/conan2prjs/actions/runs/41938302601)（2026-11-05，早期 run 同因）

## 错误日志摘录
```
conanfile.py (conan2opencvtest/0.1): Error in generate() method, line 26
	deps.generate()
PermissionError: [Errno 13] Permission denied: 'cmakedeps_macros.cmake'
```

## 原因分析
CI 脚本混用 `sudo conan install`（root 写入 profile/缓存/生成文件）与
user 级 `conan install`：先由 root 生成的 `cmakedeps_macros.cmake` 等文件
属主为 root，随后 user 级再次 generate/编译时无写权限 → PermissionError。
且脚本中 rm -rf build 在第二次 install 之前缺乏，前置产物持续存在。

## 修复内容
`.github/workflows/conan2_ubuntu22.yml` 全面重写：
1. 去掉所有 `sudo conan install`，改全程 user 级 conan（profile 用 ~/.conan2）；
2. profile detect/sed/追加 conf 收敛为一份 user 级配置；
3. 每个子项目 `conan install` 前 `rm -rf build`，cmake 使用刚下载的
   cmake-3.27.9 PATH 前缀调用。

## 验证
| run id | 结果 |
| --- | --- |
| 本次推送触发 | 待填 |
