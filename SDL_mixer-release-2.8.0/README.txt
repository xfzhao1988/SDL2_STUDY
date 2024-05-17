
SDL_mixer 2.0

/*
 *该库的最新版本可从 GitHub 获取：https://github.com/libsdl-org/SDL_mixer/releases
 */
The latest version of this library is available from GitHub:
https://github.com/libsdl-org/SDL_mixer/releases

/*
 * 由于大众的需求，这里是一个简单的多通道音频混合器。
 * 它支持 8 通道 16 位立体声音频，以及单通道音乐。它可以加载 FLAC、MP3、Ogg、VOC 和 WAV
 * 格式的音频。 它还可以加载 MIDI、MOD、和 Opus 音频，具体取决于构建选项（有关详细信息，请参阅下面的注释。）
 */
Due to popular demand, here is a simple multi-channel audio mixer.
It supports 8 channels of 16 bit stereo audio, plus a single channel of music.
It can load FLAC, MP3, Ogg, VOC, and WAV format audio. It can also load MIDI, MOD,
and Opus audio, depending on build options (see the note below for details.)

/*
 * 有关此混音器库的文档，请参阅头文件 SDL_mixer.h 以及示例 playwave.c 和 playmus.c。
 * 该文档也可在线获取：https://wiki.libsdl.org/SDL_mixer
 */
See the header file SDL_mixer.h and the examples playwave.c and playmus.c for
documentation on this mixer library. This documentation is also available online
at https://wiki.libsdl.org/SDL_mixer

/*
 * MIDI（Musical Instrument Digital Interface）是一种数字音频/音乐接口标准，
 * 用于在电子音乐设备之间传输音乐信息。它并不传输音频信号，而是传输用于控制音乐性能的指令，比如音符、音量、音色等。
 * 以下是一些关于MIDI的重要概念：
 * 消息类型：MIDI消息分为三种类型：音符消息（Note Messages），控制器消息（Control Change Messages），
 * 系统消息（System Messages）。
 *
 * 音符消息：音符消息包含关于音符的信息，比如音符号、音量、音色、持续时间等。
 *
 * 控制器消息：控制器消息用于控制音乐表现，比如改变音量、音色、音调等。
 *
 * 系统消息：系统消息用于控制全局设置，比如开始/停止/暂停播放、同步设备等。
 *
 * 通道：MIDI使用16个通道来区分不同的乐器或音轨，每个通道都可以独立地接收和处理MIDI消息。

 * MIDI在音乐产业中具有广泛的应用，包括音乐制作、电子乐器、音乐教育等领域。它提供了一种通用的
 * 音乐交互方式，使得不同厂商生产的乐器和设备可以相互协作，从而极大地促进了音乐创作和演出的便利性和灵活性。
 */
The process of mixing MIDI files to wave output is very CPU intensive, so if playing regular
WAVE files sound great, but playing MIDI files sound choppy, try using 8-bit audio, mono audio,
or lower frequencies.
将 MIDI 文件混合到波形输出的过程非常消耗 CPU 资源，因此如果播放常规 WAVE 文件听起来不错，但播放 MIDI
文件声音不稳定，请尝试使用 8 位音频、单声道音频或较低频率。

If you have built with FluidSynth support, you'll need to set the SDL_SOUNDFONTS environment variable
to a Sound Font 2 (.sf2) file containing the musical instruments you want to use for MIDI playback.
(On some Linux distributions you can install the fluid-soundfont-gm package)
如果您使用 FluidSynth 支持进行构建，则需要将 SDL_SOUNDFONTS 环境变量设置为 Sound Font 2 (.sf2) 文件，
其中包含要用于 MIDI 播放的乐器。（在某些 Linux 发行版上，您可以安装 Fluid -soundfont-gm 包）

To play MIDI files using Timidity, you'll need to get a complete set of GUS patches from:
http://www.libsdl.org/projects/mixer/timidity/timidity.tar.gz
and unpack them in /usr/local/lib under UNIX, and C:\ under Win32.
要使用 Timidity 播放 MIDI 文件，您需要从以下位置获取完整的 GUS 补丁集：
http://www.libsdl.org/projects/mixer/timidity/timidity.tar.gz
并在 UNIX 下将它们解压到 /usr/local/lib 中，在 Win32 下将它们解压到 C:\ 中。

This library is under the zlib license, see the file "LICENSE.txt" for details.
该库受 zlib 许可，有关详细信息，请参阅文件“LICENSE.txt”。

Note:
Support for software MIDI, MOD, and Opus are not included by default because of the size of the decode
libraries, but you can get them by running external/download.sh
由于解码库的大小，默认情况下不包括对软件 MIDI、MOD 和 Opus 的支持，但您可以通过运行 external/download.sh 来获取它们
- When building with CMake, you can enable the appropriate SDL2MIXER_* options defined in CMakeLists.txt.
  SDL2MIXER_VENDORED allows switching between system and vendored libraries.
- 使用 CMake 构建时，您可以启用 CMakeLists.txt 中定义的相应 SDL2MIXER_* 选项。 SDL2MIXER_VENDORED
  允许在系统库和供应商库之间切换。

- When building with configure/make, you can build and install them normally and the configure
  script will detect and use them.
- 当使用configure/make构建时，您可以正常构建和安装它们，并且configure脚本将检测并使用它们。

- When building with Visual Studio, you will need to build the libraries and then add the
  appropriate LOAD_* preprocessor define to the Visual Studio project.
- 使用 Visual Studio 构建时，您需要构建库，然后将适当的 LOAD_* 预处理器定义添加到 Visual Studio 项目中。

- When building with Xcode, you can edit the config at the top of the project to enable
  them, and you will need to include the appropriate framework in your application.
- 使用 Xcode 构建时，您可以编辑项目顶部的配置来启用它们，并且您需要在应用程序中包含适当的框架。

- For Android, you can edit the config at the top of Android.mk to enable them.
- 对于 Android，您可以编辑 Android.mk 顶部的配置来启用它们。

The default MP3 support is provided using minimp3. SDL_mixer also supports using libmpg123:
you can enable it by passing --enable-music-mp3-mpg123 to configure.
默认的 MP3 支持是使用 minimp3 提供的。 SDL_mixer 还支持使用 libmpg123：您可以通过传递
--enable-music-mp3-mpg123 进行配置来启用它。
