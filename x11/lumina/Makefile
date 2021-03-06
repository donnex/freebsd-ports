# Created by: Ken Moore <ken@pcbsd.org>
# $FreeBSD$

PORTNAME=	lumina
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-Beta2
PORTREVISION=1
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Lumina Desktop Environment

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	fluxbox>=0:x11-wm/fluxbox \
		kde4-icons-oxygen>=0:x11-themes/kde4-icons-oxygen \
		xscreensaver:x11/xscreensaver \
		xbrightness:x11/xbrightness \
		compton:x11-wm/compton \
		xrandr:x11/xrandr \
		numlockx:x11/numlockx

CONFLICTS=	lumina-devel-0*

OPTIONS_DEFINE=	MULTIMEDIA TRUEOS
OPTIONS_DEFAULT=	MULTIMEDIA
MULTIMEDIA_DESC=	Install multimedia support backend (gstreamer)
TRUEOS_DESC=	Use the TrueOS system interface settings.

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMULTIMEDIA}
RUN_DEPENDS+=	gstreamer1-plugins-core>=0:multimedia/gstreamer1-plugins-core
.endif

MAKE_JOBS_UNSAFE=yes

USE_XORG=	x11 xdamage xcb
USE_XCB=	x11extras wm ewmh util-wm
USE_LDCONFIG=	yes
USE_QT5=	core gui widgets network svg multimedia imageformats \
		buildtools_build x11extras concurrent
USES=		desktop-file-utils qmake
USE_GITHUB=	yes
GH_ACCOUNT=	trueos

#Setup the qmake configuration options
.if ${PORT_OPTIONS:MTRUEOS}
QMAKE_ARGS=	DEFAULT_SETTINGS=TrueOS
.endif

.include <bsd.port.mk>
