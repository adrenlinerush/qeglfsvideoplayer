# qeglfsvideoplayer

A very simple video player that uses QT5 to play videos using DRI/KMS without X or Wayland.

### Gentoo

1. Add my portage [overlay](https://wiki.adrenlinerush.net/doku.php?id=gentoo_portage_overlay).
2. Set Use Flags 
<pre>
media-libs/gst-plugins-base -opengl
media-libs/freetype static-libs
app-arch/bzip2 static-libs
sys-libs/zlib static-libs
media-libs/libpng static-libs
virtual/jpeg static-libs
dev-qt/qtgui X linuxfb jpeg udev evdev -libinput egl eglfs debug
media-libs/libglvnd X
dev-qt/qtmultimedia widgets gstreamer qml debug
sys-libs/zlib minizip
dev-libs/libxml2 icu
dev-qt/qtwebengine widgets -bindist debug
dev-qt/qtcore icu debug
media-libs/gst-plugins-base egl gbm opengl
media-plugins/gst-plugins-meta alsa dvd ffmpeg flac http mp3 mpeg ogg vorbis
dev-qt/qtprintsupport cups
app-text/ghostscript-gpl cups
</pre>
3. Emerge
<pre>
emerge --ask qeglfsvideoplayer
</pre>

### Armbian Bookworm (aarch64)


1. Add my apt [repo](https://wiki.adrenlinerush.net/doku.php?id=armbian_bookworm_aarch64_-_custom_packages).
2. apt-get update
3. apt-get install qeglfsvideoplayer

## Usage

<pre>
qeglfsvideoplayer videofile
</pre>

* q - quit the application
* p - toggle play/pause
* right arrow - fast forward
* left arrow - rewind
* up arrow - volume up
* down arrow - volume down



