# Nika Read Only

- Apex Legends external cheat for Linux.

## Introduction

- The goal of this project is to have a working Linux cheat that can run alongside Apex Legends on my i5-6600K 4c/4t Linux PC.
- This a modification of: [Pesci-Apu/Nika](https://github.com/Pesci-Apu/Nika).
- With an overlay taken from: [Gerosity/zap-client-Read-Only-](https://github.com/Gerosity/zap-client-Read-Only-).
- The code remains simple and clean. You can read it out and understand how the overlay is added.
- Lines were commented out with a "**//_**" prefix or added with a "**//_add**" suffix. Also "**//_begin**" and "**//_end**" was used for large blocks.

## Credits

- [x] (UC) **Acknowledge**
- [x] (UC) **Gerosity**

## Features

* [x] Window title **spoofing** (webpage title mimic)
* [x] Memory writing Glow ESP was replaced with overlay based ESP
* [x] Map radar (overlay based)
* [x] Spectators list (overlay or CLI based)
* [x] **Smooth** dynamically adjusts with performance; Firing Range settings will now act the same during matches
* [x] Added _AIMBOT_ZOOMED_MAX_MOVE_ / _AIMBOT_HIPFIRE_MAX_MOVE_ / _AIMBOT_MAX_DELTA_ to limit mouse speed
* [x] Hold SHIFT to **lock on target** and **triggerbot** auto fire, or to **super glide**
* [x] Partially disable/enable **aimbot** with CURSOR_LEFT; "**<**" symbol in the upper left corner of the screen
* [x] Toggle **ADS locking** with CURSOR_RIGHT; "**>**" symbol in the upper left corner of the screen
* [x] Quickly enable/disable **triggerbot** auto fire with CURSOR_UP; "**^**" symbol in the upper left corner of the screen
- **Bind X in-game to fire, triggerbot will use that key** (default AIMBOT_FIRING_KEY)
* [x] Toggle hitbox with CURSOR_DOWN; `body`/`neck`/`head` text in the upper left corner of the screen
* [x] Terminate process with HOME

![Screenshot.jpg](Screenshot.jpg)

### 1. Environment set up in Linux

- Install dependencies (<b>Arch</b>):
``` shell
sudo pacman -Sy libudev0 cmake xorg-server git base-devel libx11 libxtst
```

or

- Install dependencies (<b>Debian</b>):
``` shell
sudo apt-get install -y libudev-dev
sudo apt install cmake xorg-dev libglu1-mesa-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev
sudo apt install -y libudev-dev libglu1-mesa-dev libxkbcommon-dev libwayland-dev git cmake g++ gcc libinput-dev libsoil-dev
sudo apt-get install build-essential
sudo apt-get install libx11-dev
sudo apt-get install libxtst-dev
```

### 2. Build & Install GLFW

IMPORTANT: When using `nano src/egl_context.c` below, you must change:

``` shell
    _glfw.egl.EXT_present_opaque =
        extensionSupportedEGL("EGL_EXT_present_opaque");
```

into

``` shell
    _glfw.egl.EXT_present_opaque = GLFW_FALSE;
        //extensionSupportedEGL("EGL_EXT_present_opaque");
```

- For exclusively using **Wayland**:

``` shell
su
chmod 700 /root
cd /root
git clone https://github.com/glfw/glfw.git
cd glfw
nano src/egl_context.c
mkdir build
cd build
cmake .. -D GLFW_BUILD_X11=0
make
make install
```

or

- For exclusively using **X11**:

``` shell
su
chmod 700 /root
cd /root
git clone https://github.com/glfw/glfw.git
cd glfw
mkdir build
cd build
cmake .. -D GLFW_BUILD_WAYLAND=0
make
make install
```

### 3.0 Updating

- If you are updating, run this command first: `sudo rm -fr /root/Nika-Read-Only`

### 3.1 Build

``` shell
su
cd /root
git clone https://github.com/Ape-xCV/Nika-Read-Only.git
cd Nika-Read-Only
mkdir build
cd build
cmake ..
make
cp main /root/main
cp nika.ini /root/nika.ini
chmod +x main.sh
cp main.sh /root/main.sh
cp www.txt /root/www.txt
chmod +x spoof.sh
cp spoof.sh /root/spoof.sh
cp rules /root/rules
```

### 4. Run

``` shell
su
cd /root
./main.sh
```

### 5. HWID unban

- My storage serial numbers were collected most likely from **dbus**. Widely adopted Linux **systemd** `init` as currently being distributed has the security profile of an internet **meme**.
- Run `spoof.sh` then reboot.
- The following command is run by the game in this context: `dbus-send --system --dest=org.freedesktop.UDisks2 --type=method_call --print-reply  /org/freedesktop/UDisks2 org.freedesktop.DBus.ObjectManager.GetManagedObjects`

### 6. GNU MAC Changer

- Install (Arch): `sudo pacman -S macchanger`
- Install (Debian): `sudo apt install macchanger`
- Edit **spoof.sh** and modify it where needed: `sudo nano /root/spoof.sh`

### 7. CachyOS + NVIDIA proprietary driver

- Set to "**Borderless Window**" in-game, press ESC >> Settings >> Video >> Display Mode
- For KDE desktop environment (Wayland), open System Settings >> Window Management >> Window Rules >> Import... >> glfw.kwinrule
- For Xfce desktop environment (X11), go to Settings >> Window Manager Tweaks >> Accessibility >> Key used to grab and move windows: None
