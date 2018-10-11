#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/controle/conCliente.o \
	${OBJECTDIR}/controle/vector.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/modelo/daos/clienteDAO.o \
	${OBJECTDIR}/modelo/daos/tamanho.o \
	${OBJECTDIR}/visao/MenuPrincipal.o \
	${OBJECTDIR}/visao/VisaoCategoria.o \
	${OBJECTDIR}/visao/VisaoCliente.o \
	${OBJECTDIR}/visao/VisaoFilmes.o \
	${OBJECTDIR}/visao/VisaoFornecedores.o \
	${OBJECTDIR}/visao/VisaoFuncionario.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/codigo.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/codigo.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/codigo ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/controle/conCliente.o: controle/conCliente.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/conCliente.o controle/conCliente.c

${OBJECTDIR}/controle/vector.o: controle/vector.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/vector.o controle/vector.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/modelo/daos/clienteDAO.o: modelo/daos/clienteDAO.c
	${MKDIR} -p ${OBJECTDIR}/modelo/daos
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/modelo/daos/clienteDAO.o modelo/daos/clienteDAO.c

${OBJECTDIR}/modelo/daos/tamanho.o: modelo/daos/tamanho.c
	${MKDIR} -p ${OBJECTDIR}/modelo/daos
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/modelo/daos/tamanho.o modelo/daos/tamanho.c

${OBJECTDIR}/visao/MenuPrincipal.o: visao/MenuPrincipal.c
	${MKDIR} -p ${OBJECTDIR}/visao
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/visao/MenuPrincipal.o visao/MenuPrincipal.c

${OBJECTDIR}/visao/VisaoCategoria.o: visao/VisaoCategoria.c
	${MKDIR} -p ${OBJECTDIR}/visao
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/visao/VisaoCategoria.o visao/VisaoCategoria.c

${OBJECTDIR}/visao/VisaoCliente.o: visao/VisaoCliente.c
	${MKDIR} -p ${OBJECTDIR}/visao
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/visao/VisaoCliente.o visao/VisaoCliente.c

${OBJECTDIR}/visao/VisaoFilmes.o: visao/VisaoFilmes.c
	${MKDIR} -p ${OBJECTDIR}/visao
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/visao/VisaoFilmes.o visao/VisaoFilmes.c

${OBJECTDIR}/visao/VisaoFornecedores.o: visao/VisaoFornecedores.c
	${MKDIR} -p ${OBJECTDIR}/visao
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/visao/VisaoFornecedores.o visao/VisaoFornecedores.c

${OBJECTDIR}/visao/VisaoFuncionario.o: visao/VisaoFuncionario.c
	${MKDIR} -p ${OBJECTDIR}/visao
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/visao/VisaoFuncionario.o visao/VisaoFuncionario.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
