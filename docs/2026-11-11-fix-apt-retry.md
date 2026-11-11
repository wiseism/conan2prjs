# 修复 conan2prjs：runner DNS 抖动导致 apt 安装失败

## 失败信息
- Run 42443662425 两次 attempt：`E: Failed to fetch ... Temporary failure resolving 'azure.archive.ubuntu.com'`
  （xcb/qt 相关 dev 包批量下载失败，exit 100）

## 原因分析
- runner 环境瞬时 DNS 解析失败（archive/security.ubuntu.com），apt 一次失败即整步退出；
  并非代码问题（本地无影响）。

## 修复内容
- `.github/workflows/conan2_ubuntu22.yml`：apt update / apt install 各加 3 次重试循环（间隔 15-20s）。

## 验证记录
| Run | 结果 |
|---|---|
| 42443662425 两次 attempt | failure — DNS 抖动 |
| 待 re-run | 待填 |
