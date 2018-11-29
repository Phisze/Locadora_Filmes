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
	${OBJECTDIR}/controle/conCategoria.o \
	${OBJECTDIR}/controle/conCliente.o \
	${OBJECTDIR}/controle/conEntradaFilme.o \
	${OBJECTDIR}/controle/conFilme.o \
	${OBJECTDIR}/controle/conFornecedcor.o \
	${OBJECTDIR}/controle/conFuncionario.o \
	${OBJECTDIR}/controle/conImportacao.o \
	${OBJECTDIR}/controle/conLocacaoFilme.o \
	${OBJECTDIR}/controle/conLocadora.o \
	${OBJECTDIR}/controle/conPersistencia.o \
	${OBJECTDIR}/controle/feedback.o \
	${OBJECTDIR}/controle/funcoesUteis.o \
	${OBJECTDIR}/controle/vector.o \
	${OBJECTDIR}/controle/vetorCategoria.o \
	${OBJECTDIR}/controle/vetorCliente.o \
	${OBJECTDIR}/controle/vetorFilme.o \
	${OBJECTDIR}/controle/vetorFornecedor.o \
	${OBJECTDIR}/controle/vetorFuncionario.o \
	${OBJECTDIR}/controle/vetorLocadora.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/modelo/Ex_Importacao.o \
	${OBJECTDIR}/modelo/NotaFiscal.o \
	${OBJECTDIR}/modelo/daos/categoriaDAO.o \
	${OBJECTDIR}/modelo/daos/clienteDAO.o \
	${OBJECTDIR}/modelo/daos/contaDAO.o \
	${OBJECTDIR}/modelo/daos/filmeDAO.o \
	${OBJECTDIR}/modelo/daos/fornecedorDAO.o \
	${OBJECTDIR}/modelo/daos/funcionarioDAO.o \
	${OBJECTDIR}/modelo/daos/locacaoDAO.o \
	${OBJECTDIR}/modelo/daos/locadoraDAO.o \
	${OBJECTDIR}/modelo/daos/tamanho.o \
	${OBJECTDIR}/visao/MenuPrincipal.o \
	${OBJECTDIR}/visao/VisaoCliente.o \
	${OBJECTDIR}/visao/VisaoFilmes.o \
	${OBJECTDIR}/visao/VisaoFornecedor.o \
	${OBJECTDIR}/visao/VisaoFuncionario.o \
	${OBJECTDIR}/visao/locacao_filme.o \
	${OBJECTDIR}/visao/visaoLocadora.o


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

${OBJECTDIR}/controle/conCategoria.o: controle/conCategoria.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/conCategoria.o controle/conCategoria.c

${OBJECTDIR}/controle/conCliente.o: controle/conCliente.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/conCliente.o controle/conCliente.c

${OBJECTDIR}/controle/conEntradaFilme.o: controle/conEntradaFilme.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/conEntradaFilme.o controle/conEntradaFilme.c

${OBJECTDIR}/controle/conFilme.o: controle/conFilme.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/conFilme.o controle/conFilme.c

${OBJECTDIR}/controle/conFornecedcor.o: controle/conFornecedcor.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/conFornecedcor.o controle/conFornecedcor.c

${OBJECTDIR}/controle/conFuncionario.o: controle/conFuncionario.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/conFuncionario.o controle/conFuncionario.c

${OBJECTDIR}/controle/conImportacao.o: controle/conImportacao.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/conImportacao.o controle/conImportacao.c

${OBJECTDIR}/controle/conLocacaoFilme.o: controle/conLocacaoFilme.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/conLocacaoFilme.o controle/conLocacaoFilme.c

${OBJECTDIR}/controle/conLocadora.o: controle/conLocadora.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/conLocadora.o controle/conLocadora.c

${OBJECTDIR}/controle/conPersistencia.o: controle/conPersistencia.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/conPersistencia.o controle/conPersistencia.c

${OBJECTDIR}/controle/feedback.o: controle/feedback.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/feedback.o controle/feedback.c

${OBJECTDIR}/controle/funcoesUteis.o: controle/funcoesUteis.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/funcoesUteis.o controle/funcoesUteis.c

${OBJECTDIR}/controle/vector.o: controle/vector.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/vector.o controle/vector.c

${OBJECTDIR}/controle/vetorCategoria.o: controle/vetorCategoria.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/vetorCategoria.o controle/vetorCategoria.c

${OBJECTDIR}/controle/vetorCliente.o: controle/vetorCliente.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/vetorCliente.o controle/vetorCliente.c

${OBJECTDIR}/controle/vetorFilme.o: controle/vetorFilme.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/vetorFilme.o controle/vetorFilme.c

${OBJECTDIR}/controle/vetorFornecedor.o: controle/vetorFornecedor.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/vetorFornecedor.o controle/vetorFornecedor.c

${OBJECTDIR}/controle/vetorFuncionario.o: controle/vetorFuncionario.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/vetorFuncionario.o controle/vetorFuncionario.c

${OBJECTDIR}/controle/vetorLocadora.o: controle/vetorLocadora.c
	${MKDIR} -p ${OBJECTDIR}/controle
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/controle/vetorLocadora.o controle/vetorLocadora.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/modelo/Ex_Importacao.o: modelo/Ex_Importacao.c
	${MKDIR} -p ${OBJECTDIR}/modelo
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/modelo/Ex_Importacao.o modelo/Ex_Importacao.c

${OBJECTDIR}/modelo/NotaFiscal.o: modelo/NotaFiscal.c
	${MKDIR} -p ${OBJECTDIR}/modelo
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/modelo/NotaFiscal.o modelo/NotaFiscal.c

${OBJECTDIR}/modelo/daos/categoriaDAO.o: modelo/daos/categoriaDAO.c
	${MKDIR} -p ${OBJECTDIR}/modelo/daos
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/modelo/daos/categoriaDAO.o modelo/daos/categoriaDAO.c

${OBJECTDIR}/modelo/daos/clienteDAO.o: modelo/daos/clienteDAO.c
	${MKDIR} -p ${OBJECTDIR}/modelo/daos
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/modelo/daos/clienteDAO.o modelo/daos/clienteDAO.c

${OBJECTDIR}/modelo/daos/contaDAO.o: modelo/daos/contaDAO.c
	${MKDIR} -p ${OBJECTDIR}/modelo/daos
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/modelo/daos/contaDAO.o modelo/daos/contaDAO.c

${OBJECTDIR}/modelo/daos/filmeDAO.o: modelo/daos/filmeDAO.c
	${MKDIR} -p ${OBJECTDIR}/modelo/daos
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/modelo/daos/filmeDAO.o modelo/daos/filmeDAO.c

${OBJECTDIR}/modelo/daos/fornecedorDAO.o: modelo/daos/fornecedorDAO.c
	${MKDIR} -p ${OBJECTDIR}/modelo/daos
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/modelo/daos/fornecedorDAO.o modelo/daos/fornecedorDAO.c

${OBJECTDIR}/modelo/daos/funcionarioDAO.o: modelo/daos/funcionarioDAO.c
	${MKDIR} -p ${OBJECTDIR}/modelo/daos
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/modelo/daos/funcionarioDAO.o modelo/daos/funcionarioDAO.c

${OBJECTDIR}/modelo/daos/locacaoDAO.o: modelo/daos/locacaoDAO.c
	${MKDIR} -p ${OBJECTDIR}/modelo/daos
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/modelo/daos/locacaoDAO.o modelo/daos/locacaoDAO.c

${OBJECTDIR}/modelo/daos/locadoraDAO.o: modelo/daos/locadoraDAO.c
	${MKDIR} -p ${OBJECTDIR}/modelo/daos
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/modelo/daos/locadoraDAO.o modelo/daos/locadoraDAO.c

${OBJECTDIR}/modelo/daos/tamanho.o: modelo/daos/tamanho.c
	${MKDIR} -p ${OBJECTDIR}/modelo/daos
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/modelo/daos/tamanho.o modelo/daos/tamanho.c

${OBJECTDIR}/visao/MenuPrincipal.o: visao/MenuPrincipal.c
	${MKDIR} -p ${OBJECTDIR}/visao
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/visao/MenuPrincipal.o visao/MenuPrincipal.c

${OBJECTDIR}/visao/VisaoCliente.o: visao/VisaoCliente.c
	${MKDIR} -p ${OBJECTDIR}/visao
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/visao/VisaoCliente.o visao/VisaoCliente.c

${OBJECTDIR}/visao/VisaoFilmes.o: visao/VisaoFilmes.c
	${MKDIR} -p ${OBJECTDIR}/visao
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/visao/VisaoFilmes.o visao/VisaoFilmes.c

${OBJECTDIR}/visao/VisaoFornecedor.o: visao/VisaoFornecedor.c
	${MKDIR} -p ${OBJECTDIR}/visao
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/visao/VisaoFornecedor.o visao/VisaoFornecedor.c

${OBJECTDIR}/visao/VisaoFuncionario.o: visao/VisaoFuncionario.c
	${MKDIR} -p ${OBJECTDIR}/visao
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/visao/VisaoFuncionario.o visao/VisaoFuncionario.c

${OBJECTDIR}/visao/locacao_filme.o: visao/locacao_filme.c
	${MKDIR} -p ${OBJECTDIR}/visao
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/visao/locacao_filme.o visao/locacao_filme.c

${OBJECTDIR}/visao/visaoLocadora.o: visao/visaoLocadora.c
	${MKDIR} -p ${OBJECTDIR}/visao
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/visao/visaoLocadora.o visao/visaoLocadora.c

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
