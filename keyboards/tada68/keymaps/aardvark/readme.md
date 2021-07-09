#Aardvark#

This keymap is being optimized for writing code on a Swedish keyboard. Should
be the same layout on a Finnish board, and Norwegian and Danish layouts aren't
much different.

Tried to maintain the original keyboard layout, but also giving "hotkeys" for
symbols used in programming: (){}[] and so forth. Those that are in weird
positions.

It's basically a 65% ISO layout, three keys between space and arrows.

CAPS: use right ctrl and right shift to get CAPS.
Actual CAPS button is used to reach symbol layer. []()=<> and so forth...



# TADA68

A compact 65% keyboard.

* Keyboard Maintainer: QMK Community
* Hardware Supported: TADA68 PCB
* Hardware Availability: [kbdfans](https://kbdfans.myshopify.com/products/tada68-mechanical-keyboard-gateron-swtich-65-layout-dye-sub-keycaps-cherry-profils?variant=34710238797), [kbdist](http://www.kbdist.com/)

Make example for this keyboard (after setting up your build environment):

    make tada68:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Firmware Format

Out of the box the tada68 uses a .bin firmware file instead of a .hex like other custom keyboards. By default QMK will build and copy the correct .bin file for you. If for some reason you need a hex file instead, you can add `:hex` to your make command, or look inside `qmk_firmware/.build` to find the hex file.

## Flashing Instructions (Linux)

*Use these instructions at your own risk. Mount settings originally found at https://www.reddit.com/r/MechanicalKeyboards/comments/8e2nnp/help_problems_flashing_firmware_on_tada68_from/*

1) from the `qmk_firmware\` directory run:
```
$ make tada68:default:flashbin
```

2) Connect your keyboard to the computer, hit the reset button on the TADA, the lights will start flashing.

3) A new entry should appear at `/dev/sd*`. Mount the board using this command:


```
sudo mount -t vfat -o rw,nosuid,nodev,relatime,uid=1000,gid=1000,fmask=0022,dmask=0022,codepage=437,iocharset=iso8859-1,shortname=mixed,showexec,utf8,flush,errors=remount-ro,uhelper=udisks2 <path to device> /mnt/tada68
```

4) Back up the original firmware

`mv /mnt/tada68/FLASH.BIN ~`

5) Copy over your new firmware to the keybaord

`cp <path to your qmk_firmware folder>/FLASH.bin /mnt/tada68`
cp ~/ Dropbox/Projekt/endgame/qmk_firmware/tada68_aardvark.bin /mnt/tada68

5) *Do not eject the USB device.* Hit ESC on the keyboard. The lights will stop flashing and your firmware is loaded!

Make sure not to use the one called FLASH.bin or similar. Use keyboard:name:flashbin
