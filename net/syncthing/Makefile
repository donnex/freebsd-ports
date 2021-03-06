# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	syncthing
PORTVERSION=	0.14.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Encrypted file sync tool

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
USE_RC_SUBR=	syncthing
PLIST_FILES=	bin/syncthing
PORTDOCS=	*

USERS=		syncthing
GROUPS=		syncthing

STRIP=		# stripping can break go binaries

post-patch:
	@cd ${WRKSRC} ; ${MKDIR} src/github.com/${PORTNAME}/${PORTNAME} ; \
		${MV} .gitattributes .gitignore .mailmap AUTHORS CONDUCT.md \
		CONTRIBUTING.md ISSUE_TEMPLATE.md LICENSE NICKS debtpl \
		PULL_REQUEST_TEMPLATE.md README.md assets build.go build.sh cmd \
		etc gui lib man script test vendor \
		src/github.com/${PORTNAME}/${PORTNAME}

do-build:
	# timestamp here refers to source, not build time
	@cd ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME} ; \
		${SETENV} GOPATH=${WRKSRC} go run build.go -no-upgrade=true -version v${PORTVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME}/bin/syncthing \
		${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in AUTHORS CONTRIBUTING.md LICENSE README.md
	${INSTALL_MAN} ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME}/${x} \
		${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
