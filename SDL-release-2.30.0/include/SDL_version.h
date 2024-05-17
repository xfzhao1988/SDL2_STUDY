/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2024 Sam Lantinga <slouken@libsdl.org>
  简单直接媒体层
  版权所有 (C) 1997-2024 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  本软件按“原样”提供，没有任何明示或暗示的保证。 在任何情况下，作者均不对因
  使用本软件而造成的任何损害承担责任。

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:
  任何人均有权出于任何目的（包括商业应用）使用本软件，并自由地修改和重新分发本软件，
  但须遵守以下限制：

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
     不得谎报本软件的出处； 您不得声称您编写了原始软件。 如果您在产品中使用此软件，
     我们将不胜感激，但不是必需的。

  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
     更改的源版本必须明确标记，并且不得歪曲为原始软件。

  3. This notice may not be removed or altered from any source distribution.
     不得从任何来源分发中删除或更改本通知。
*/

/**
 *  \file SDL_version.h
 *
 *  This header defines the current SDL version.
 *  该标头定义当前的 SDL 版本。
 */

#ifndef SDL_version_h_
#define SDL_version_h_

#include "SDL_stdinc.h"

#include "begin_code.h"
/* Set up for C function definitions, even when using C++
 * 设置 C 函数定义，即使使用 C++ 时也是如此
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * Information about the version of SDL in use.
 * 有关正在使用的 SDL 版本的信息。
 *
 * Represents the library's version as three levels: major revision
 * (increments with massive changes, additions, and enhancements),
 * minor revision (increments with backwards-compatible changes to the
 * major revision), and patchlevel (increments with fixes to the minor
 * revision).
 * 将库的版本表示为三个级别：主要修订版（包含大量更改、添加和增强的增量）、
 * 次要修订版（包含对主要修订版的向后兼容更改的增量）和补丁级别（包含对次要修
 * 订版的修复的增量）。
 *
 * \sa SDL_VERSION
 * \sa SDL_GetVersion
 */
//done
typedef struct SDL_version
{
    Uint8 major;        /**< major version 主要版本 */
    Uint8 minor;        /**< minor version 次要版本 */
    Uint8 patch;        /**< update version 更新版本 */
} SDL_version;

/* Printable format: "%d.%d.%d", MAJOR, MINOR, PATCHLEVEL
 * 可打印格式：“%d.%d.%d”、MAJOR、MINOR、PATCHLEVEL
*/
//done
#define SDL_MAJOR_VERSION   2
#define SDL_MINOR_VERSION   30
#define SDL_PATCHLEVEL      0

/**
 * Macro to determine SDL version program was compiled against.
 * 用于确定编译 SDL 版本程序的宏。
 *
 * This macro fills in a SDL_version structure with the version of the
 * library you compiled against. This is determined by what header the
 * compiler uses. Note that if you dynamically linked the library, you might
 * have a slightly newer or older version at runtime. That version can be
 * determined with SDL_GetVersion(), which, unlike SDL_VERSION(),
 * is not a macro.
 * 该宏使用您编译的库的版本填充 SDL_version 结构。 这是由编译器使用的标头决定的。
 * 请注意，如果您动态链接该库，则在运行时可能会拥有稍新或稍旧的版本。 该版本可以使用
 * SDL_GetVersion() 确定，与 SDL_VERSION() 不同，SDL_GetVersion() 不是宏。
 *
 * \param x A pointer to a SDL_version struct to initialize.
 * 指向要初始化的 SDL_version 结构的指针。
 *
 * \sa SDL_version
 * \sa SDL_GetVersion
 */
//done
#define SDL_VERSION(x)                          \
{                                   \
    (x)->major = SDL_MAJOR_VERSION;                 \
    (x)->minor = SDL_MINOR_VERSION;                 \
    (x)->patch = SDL_PATCHLEVEL;                    \
}

/* TODO: Remove this whole block in SDL 3
 * TODO: 在 SDL 3 中删除整个块
 */
#if SDL_MAJOR_VERSION < 3
/**
 *  This macro turns the version numbers into a numeric value:
 *  该宏将版本号转换为数值：
 *  \verbatim
    (1,2,3) -> (1203)
    \endverbatim
 *
 *  This assumes that there will never be more than 100 patchlevels.
 *  这是假设补丁级别永远不会超过 100 个。
 *
 *  In versions higher than 2.9.0, the minor version overflows into
 *  the thousands digit: for example, 2.23.0 is encoded as 4300,
 *  and 2.255.99 would be encoded as 25799.
 *  This macro will not be available in SDL 3.x.
 *  在高于 2.9.0 的版本中，次要版本会溢出到千位数：例如，2.23.0 编码为 4300，
 *  2.255.99 编码为 25799。该宏在 SDL 3.x 中不可用。
 */
//done
#define SDL_VERSIONNUM(X, Y, Z)                     \
    ((X)*1000 + (Y)*100 + (Z))

/**
 *  This is the version number macro for the current SDL version.
 *  这是当前 SDL 版本的版本号宏。
 *
 *  In versions higher than 2.9.0, the minor version overflows into
 *  the thousands digit: for example, 2.23.0 is encoded as 4300.
 *  This macro will not be available in SDL 3.x.
 *  在高于 2.9.0 的版本中，次要版本会溢出到千位数：例如，2.23.0 编码为 4300。该宏在 SDL 3.x 中不可用。
 *
 *  Deprecated, use SDL_VERSION_ATLEAST or SDL_VERSION instead.
 *  已弃用，请改用 SDL_VERSION_ATLEAST 或 SDL_VERSION。
 */
//done
#define SDL_COMPILEDVERSION \
    SDL_VERSIONNUM(SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_PATCHLEVEL)
#endif /* SDL_MAJOR_VERSION < 3 */

/**
 *  This macro will evaluate to true if compiled with SDL at least X.Y.Z.
 *  如果使用 SDL 至少 X.Y.Z 进行编译，则该宏的计算结果为 true。
 */
#define SDL_VERSION_ATLEAST(X, Y, Z) \
    ((SDL_MAJOR_VERSION >= X) && \
     (SDL_MAJOR_VERSION > X || SDL_MINOR_VERSION >= Y) && \
     (SDL_MAJOR_VERSION > X || SDL_MINOR_VERSION > Y || SDL_PATCHLEVEL >= Z))

/**
 * Get the version of SDL that is linked against your program.
 *
 * If you are linking to SDL dynamically, then it is possible that the current
 * version will be different than the version you compiled against. This
 * function returns the current version, while SDL_VERSION() is a macro that
 * tells you what version you compiled with.
 *
 * This function may be called safely at any time, even before SDL_Init().
 *
 * \param ver the SDL_version structure that contains the version information
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_GetRevision
 */
extern DECLSPEC void SDLCALL SDL_GetVersion(SDL_version * ver);

/**
 * Get the code revision of SDL that is linked against your program.
 *
 * This value is the revision of the code you are linked with and may be
 * different from the code you are compiling with, which is found in the
 * constant SDL_REVISION.
 *
 * The revision is arbitrary string (a hash value) uniquely identifying the
 * exact revision of the SDL library in use, and is only useful in comparing
 * against other revisions. It is NOT an incrementing number.
 *
 * If SDL wasn't built from a git repository with the appropriate tools, this
 * will return an empty string.
 *
 * Prior to SDL 2.0.16, before development moved to GitHub, this returned a
 * hash for a Mercurial repository.
 *
 * You shouldn't use this function for anything but logging it for debugging
 * purposes. The string is not intended to be reliable in any way.
 *
 * \returns an arbitrary string, uniquely identifying the exact revision of
 *          the SDL library in use.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_GetVersion
 */
extern DECLSPEC const char *SDLCALL SDL_GetRevision(void);

/**
 * Obsolete function, do not use.
 *
 * When SDL was hosted in a Mercurial repository, and was built carefully,
 * this would return the revision number that the build was created from. This
 * number was not reliable for several reasons, but more importantly, SDL is
 * now hosted in a git repository, which does not offer numbers at all, only
 * hashes. This function only ever returns zero now. Don't use it.
 *
 * Before SDL 2.0.16, this might have returned an unreliable, but non-zero
 * number.
 *
 * \deprecated Use SDL_GetRevision() instead; if SDL was carefully built, it
 *             will return a git hash.
 *
 * \returns zero, always, in modern SDL releases.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_GetRevision
 */
extern SDL_DEPRECATED DECLSPEC int SDLCALL SDL_GetRevisionNumber(void);


/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif
#include "close_code.h"

#endif /* SDL_version_h_ */

/* vi: set ts=4 sw=4 expandtab: */
