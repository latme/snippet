[TOC]

# Ubuntu系统常见配置

## 创建桌面快捷方式

**pycharm**

```ini
# vim /usr/share/applications/pycharm.desktop

[Desktop Entry]
Version=2020.1.2
Name=Pycharm
Type=Application
Icon=/opt/pycharm-community-2020.1.2/bin/pycharm.png
Exec=sh /opt/pycharm-community-2020.1.2/bin/pycharm.sh
MimeType=application/x-py;
Name[en_US]=pycharm
```

**eclipse**

```ini
# sudo vim /usr/share/applications/eclipse.desktop

[Desktop Entry]
Name=Eclipse
Type=Application
Comment=eclipse ide
Icon=/opt/eclipse/icon.xpm
Exec=/opt/eclipse/eclipse
MimeType=application/x-py;
Name[en_US]=eclipse
```

