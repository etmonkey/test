#!/bin/bash

trash_dir="/srv/recycle/"
mkdir -p "$trash_dir"  # 确保回收站存在
args=()
# 过滤掉以 "-" 开头的参数（选项）
for arg in "$@"; do
  [[ "$arg" != -* ]] && args+=("$arg")
done
# 若无有效参数，报错退出
if [[ ${#args[@]} -eq 0 ]]; then
  echo "错误：请指定要删除的文件。"
  return 1
fi
# 移动文件到回收站，避免文件名含特殊字符
mv --backup=numbered -t "$trash_dir/" "${args[@]}" &&
echo "文件已移动到回收站: $trash_dir"

