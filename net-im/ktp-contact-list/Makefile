# $FreeBSD$

PORTNAME=	ktp-contact-list
PORTVERSION=	${KTP_VERSION}
CATEGORIES=	net-im kde
MASTER_SITES=	KDE/${KTP_BRANCH}/kde-telepathy/${PORTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE instant messaging contact list application

LIB_DEPENDS=	libtelepathy-qt4.so:net-im/telepathy-qt4 \
		libtelepathy-logger-qt4.so:net-im/telepathy-logger-qt4 \
		libktpcommoninternalsprivate.so:net-im/ktp-common-internals

USE_KDE4=	kdelibs automoc4
USE_QT4=	corelib moc_build qmake_build rcc_build uic_build
USES=		cmake gettext tar:bzip2

.include <bsd.port.mk>
