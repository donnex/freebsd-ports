# $FreeBSD$

PORTNAME=	rainloop
PORTVERSION=	1.10.2
CATEGORIES?=	mail www
MASTER_SITES=	http://repository.rainloop.net/v2/webmail/${PORTVERSION}/
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}.${RBUILD}-${RHASH}

MAINTAINER=	loic.blot@unix-experience.fr
COMMENT=	Modern and interactive webmail

.if !defined(PKGNAMESUFFIX)
LICENSE=	RainLoop
LICENSE_NAME=	RainLoop Software License
LICENSE_TEXT=	License can be found at: http://www.rainloop.net/licensing/
LICENSE_PERMS=	auto-accept
.endif

.if !defined(PKGNAMESUFFIX)
# Refresh using info from http://repository.rainloop.net/v2/core.stable.json
RHASH=		d0fd048a2d32f3838cf32a72d97959ee
.endif

.if defined(PKGNAMESUFFIX)
# Refresh using info from http://repository.rainloop.net/v2/core.open.json
RHASH=		df00be1a3ed3b171ed1dd0806b2aa5b7
.endif

# Refresh using info from http://repository.rainloop.net/v2/core.(stable|open).json
RBUILD=		141

.if !defined(PKGNAMESUFFIX)
RESTRICTED=	Redistribution in any form is prohibited
.endif
USES=		php:web zip
NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes
USE_PHP=	curl iconv json xml dom openssl pcre spl zlib
RVER=		${PORTVERSION}.${RBUILD}
PLIST_SUB=	VER="${RVER}" WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

OPTIONS_RADIO=		DB
OPTIONS_RADIO_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	SQLITE

MYSQL_USE=	PHP=pdo_mysql
PGSQL_USE=	PHP=pdo_pgsql
SQLITE_USE=	PHP=pdo_sqlite

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/* ${STAGEDIR}${WWWDIR}/data
	${INSTALL_DATA} ${WRKSRC}/index.php ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} rainloop ${STAGEDIR}${WWWDIR})
# Prune empty dirs
	@${FIND} ${STAGEDIR}${WWWDIR}/${PORTNAME}/v/${RVER} -type d -empty -delete

.include <bsd.port.mk>
