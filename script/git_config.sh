#!/bin/bash


## alias config
# global config: ~/.gitconfig
#  local config: .git/config
git config --global alias.b   branch
git config --global alias.cm  commit
git config --global alias.co  checkout
git config --global alias.ar  archive
git config --global alias.dt  difftool
git config --global alias.mt  mergetool
git config --global alias.wt  worktree
git config --global alias.s   'status --short'
git config --global alias.l   'log --graph --decorate'
git config --global alias.lo  'log --graph --decorate --oneline'
git config --global alias.lp  'log --graph --decorate -p'
git config --global alias.ln  'log --graph --decorate --name-status'
git config --global alias.sn  'show --name-status'
git config --global alias.cp  cherry-pick
git config --global alias.fp  format-patch

