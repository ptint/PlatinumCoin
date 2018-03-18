include $(top_srcdir)/src/Makefile.include

AM_CPPFLAGS += -I$(top_srcdir)/src \
  -I$(top_builddir)/src/qt \
  -I$(top_builddir)/src/qt/forms \
  $(PROTOBUF_CFLAGS) \
  $(QR_CFLAGS) \
  -fpermissive -ffloat-store -std=c++11 -D__STDC_LIMIT_MACROS -D__USE_MINGW_ANSI_STDIO
bin_PROGRAMS = platinumcoin-qt
noinst_LIBRARIES = libplatinumcoinqt.a
SUBDIRS = . 
DIST_SUBDIRS = . 

# platinumcoin qt core #
QT_TS = \
  locale/platinumcoin_ach.ts \
  locale/platinumcoin_af_ZA.ts \
  locale/platinumcoin_ar.ts \
  locale/platinumcoin_be_BY.ts \
  locale/platinumcoin_bg.ts \
  locale/platinumcoin_bs.ts \
  locale/platinumcoin_ca_ES.ts \
  locale/platinumcoin_ca.ts \
  locale/platinumcoin_ca@valencia.ts \
  locale/platinumcoin_cmn.ts \
  locale/platinumcoin_cs.ts \
  locale/platinumcoin_cy.ts \
  locale/platinumcoin_da.ts \
  locale/platinumcoin_de_AT.ts \
  locale/platinumcoin_de.ts \
  locale/platinumcoin_el_GR.ts \
  locale/platinumcoin_en.ts \
  locale/platinumcoin_eo.ts \
  locale/platinumcoin_es_CL.ts \
  locale/platinumcoin_es_DO.ts \
  locale/platinumcoin_es_MX.ts \
  locale/platinumcoin_es.ts \
  locale/platinumcoin_es_UY.ts \
  locale/platinumcoin_et.ts \
  locale/platinumcoin_eu_ES.ts \
  locale/platinumcoin_fa_IR.ts \
  locale/platinumcoin_fa.ts \
  locale/platinumcoin_fi.ts \
  locale/platinumcoin_fr_CA.ts \
  locale/platinumcoin_fr.ts \
  locale/platinumcoin_gl.ts \
  locale/platinumcoin_gu_IN.ts \
  locale/platinumcoin_he.ts \
  locale/platinumcoin_hi_IN.ts \
  locale/platinumcoin_hr.ts \
  locale/platinumcoin_hu.ts \
  locale/platinumcoin_id_ID.ts \
  locale/platinumcoin_it.ts \
  locale/platinumcoin_ja.ts \
  locale/platinumcoin_ka.ts \
  locale/platinumcoin_kk_KZ.ts \
  locale/platinumcoin_ko_KR.ts \
  locale/platinumcoin_ky.ts \
  locale/platinumcoin_la.ts \
  locale/platinumcoin_lt.ts \
  locale/platinumcoin_lv_LV.ts \
  locale/platinumcoin_ms_MY.ts \
  locale/platinumcoin_nb.ts \
  locale/platinumcoin_nl.ts \
  locale/platinumcoin_pam.ts \
  locale/platinumcoin_pl.ts \
  locale/platinumcoin_pt_BR.ts \
  locale/platinumcoin_pt_PT.ts \
  locale/platinumcoin_ro_RO.ts \
  locale/platinumcoin_ru.ts \
  locale/platinumcoin_sah.ts \
  locale/platinumcoin_sk.ts \
  locale/platinumcoin_sl_SI.ts \
  locale/platinumcoin_sq.ts \
  locale/platinumcoin_sr.ts \
  locale/platinumcoin_sv.ts \
  locale/platinumcoin_th_TH.ts \
  locale/platinumcoin_tr.ts \
  locale/platinumcoin_uk.ts \
  locale/platinumcoin_ur_PK.ts \
  locale/platinumcoin_uz@Cyrl.ts \
  locale/platinumcoin_vi.ts \
  locale/platinumcoin_vi_VN.ts \
  locale/platinumcoin_zh_CN.ts \
  locale/platinumcoin_zh_HK.ts \
  locale/platinumcoin_zh_TW.ts

QT_FORMS_UI = \
  forms/aboutdialog.ui \
  forms/addressbookpage.ui \
  forms/askpassphrasedialog.ui \
  forms/coincontroldialog.ui \
  forms/editaddressdialog.ui \
  forms/helpmessagedialog.ui \
  forms/intro.ui \
  forms/openuridialog.ui \
  forms/optionsdialog.ui \
  forms/overviewpage.ui \
  forms/receivecoinsdialog.ui \
  forms/receiverequestdialog.ui \
  forms/rpcconsole.ui \
  forms/sendcoinsdialog.ui \
  forms/sendcoinsentry.ui \
  forms/signverifymessagedialog.ui \
  forms/transactiondescdialog.ui

QT_MOC_CPP = \
  moc_addressbookpage.cpp \
  moc_addresstablemodel.cpp \
  moc_askpassphrasedialog.cpp \
  moc_platinumcoinaddressvalidator.cpp \
  moc_platinumcoinamountfield.cpp \
  moc_platinumcoingui.cpp \
  moc_platinumcoinunits.cpp \
  moc_clientmodel.cpp \
  moc_coincontroldialog.cpp \
  moc_coincontroltreewidget.cpp \
  moc_csvmodelwriter.cpp \
  moc_editaddressdialog.cpp \
  moc_guiutil.cpp \
  moc_intro.cpp \
  moc_macdockiconhandler.cpp \
  moc_macnotificationhandler.cpp \
  moc_monitoreddatamapper.cpp \
  moc_notificator.cpp \
  moc_openuridialog.cpp \
  moc_optionsdialog.cpp \
  moc_optionsmodel.cpp \
  moc_overviewpage.cpp \
  moc_paymentserver.cpp \
  moc_qvalidatedlineedit.cpp \
  moc_qvaluecombobox.cpp \
  moc_receivecoinsdialog.cpp \
  moc_receiverequestdialog.cpp \
  moc_recentrequeststablemodel.cpp \
  moc_rpcconsole.cpp \
  moc_sendcoinsdialog.cpp \
  moc_sendcoinsentry.cpp \
  moc_signverifymessagedialog.cpp \
  moc_splashscreen.cpp \
  moc_trafficgraphwidget.cpp \
  moc_transactiondesc.cpp \
  moc_transactiondescdialog.cpp \
  moc_transactionfilterproxy.cpp \
  moc_transactiontablemodel.cpp \
  moc_transactionview.cpp \
  moc_utilitydialog.cpp \
  moc_walletframe.cpp \
  moc_walletmodel.cpp \
  moc_walletview.cpp

PLATINUMCOIN_MM = \
  macdockiconhandler.mm \
  macnotificationhandler.mm

QT_MOC = \
  platinumcoin.moc \
  intro.moc \
  overviewpage.moc \
  rpcconsole.moc

QT_QRC_CPP = qrc_platinumcoin.cpp
QT_QRC = platinumcoin.qrc

PROTOBUF_CC = paymentrequest.pb.cc
PROTOBUF_H = paymentrequest.pb.h
PROTOBUF_PROTO = paymentrequest.proto

PLATINUMCOIN_QT_H = \
  addressbookpage.h \
  addresstablemodel.h \
  askpassphrasedialog.h \
  platinumcoinaddressvalidator.h \
  platinumcoinamountfield.h \
  platinumcoingui.h \
  platinumcoinunits.h \
  clientmodel.h \
  coincontroldialog.h \
  coincontroltreewidget.h \
  csvmodelwriter.h \
  editaddressdialog.h \
  guiconstants.h \
  guiutil.h \
  intro.h \
  macdockiconhandler.h \
  macnotificationhandler.h \
  monitoreddatamapper.h \
  notificator.h \
  openuridialog.h \
  optionsdialog.h \
  optionsmodel.h \
  overviewpage.h \
  paymentrequestplus.h \
  paymentserver.h \
  qvalidatedlineedit.h \
  qvaluecombobox.h \
  receivecoinsdialog.h \
  receiverequestdialog.h \
  recentrequeststablemodel.h \
  rpcconsole.h \
  sendcoinsdialog.h \
  sendcoinsentry.h \
  signverifymessagedialog.h \
  splashscreen.h \
  trafficgraphwidget.h \
  transactiondesc.h \
  transactiondescdialog.h \
  transactionfilterproxy.h \
  transactionrecord.h \
  transactiontablemodel.h \
  transactionview.h \
  utilitydialog.h \
  walletframe.h \
  walletmodel.h \
  walletmodeltransaction.h \
  walletview.h

RES_ICONS = \
  res/icons/add.png \
  res/icons/address-book.png \
  res/icons/platinumcoin.ico \
  res/icons/platinumcoin.png \
  res/icons/platinumcoin_testnet.ico \
  res/icons/platinumcoin_testnet.png \
  res/icons/clock1.png \
  res/icons/clock2.png \
  res/icons/clock3.png \
  res/icons/clock4.png \
  res/icons/clock5.png \
  res/icons/configure.png \
  res/icons/connect0_16.png \
  res/icons/connect1_16.png \
  res/icons/connect2_16.png \
  res/icons/connect3_16.png \
  res/icons/connect4_16.png \
  res/icons/debugwindow.png \
  res/icons/edit.png \
  res/icons/editcopy.png \
  res/icons/editpaste.png \
  res/icons/export.png \
  res/icons/filesave.png \
  res/icons/history.png \
  res/icons/key.png \
  res/icons/lock_closed.png \
  res/icons/lock_open.png \
  res/icons/overview.png \
  res/icons/qrcode.png \
  res/icons/quit.png \
  res/icons/receive.png \
  res/icons/remove.png \
  res/icons/send.png \
  res/icons/synced.png \
  res/icons/toolbar.png \
  res/icons/toolbar_testnet.png \
  res/icons/transaction0.png \
  res/icons/transaction2.png \
  res/icons/transaction_conflicted.png \
  res/icons/tx_inout.png \
  res/icons/tx_input.png \
  res/icons/tx_output.png \
  res/icons/tx_mined.png

PLATINUMCOIN_QT_CPP = \
  platinumcoin.cpp \
  platinumcoinaddressvalidator.cpp \
  platinumcoinamountfield.cpp \
  platinumcoingui.cpp \
  platinumcoinunits.cpp \
  clientmodel.cpp \
  csvmodelwriter.cpp \
  guiutil.cpp \
  intro.cpp \
  monitoreddatamapper.cpp \
  notificator.cpp \
  optionsdialog.cpp \
  optionsmodel.cpp \
  qvalidatedlineedit.cpp \
  qvaluecombobox.cpp \
  rpcconsole.cpp \
  splashscreen.cpp \
  trafficgraphwidget.cpp \
  utilitydialog.cpp

if ENABLE_WALLET
PLATINUMCOIN_QT_CPP += \
  addressbookpage.cpp \
  addresstablemodel.cpp \
  askpassphrasedialog.cpp \
  coincontroldialog.cpp \
  coincontroltreewidget.cpp \
  editaddressdialog.cpp \
  openuridialog.cpp \
  overviewpage.cpp \
  paymentrequestplus.cpp \
  receivecoinsdialog.cpp \
  receiverequestdialog.cpp \
  recentrequeststablemodel.cpp \
  sendcoinsentry.cpp \
  transactiondescdialog.cpp \
  transactionfilterproxy.cpp \
  transactiontablemodel.cpp \
  transactionview.cpp \
  walletframe.cpp \
  walletmodeltransaction.cpp \
  walletview.cpp \
  paymentserver.cpp \
  walletmodel.cpp \
  signverifymessagedialog.cpp \
  sendcoinsdialog.cpp \
  transactionrecord.cpp \
  transactiondesc.cpp
endif

RES_IMAGES = \
  res/images/about.png \
  res/images/splash.png \
  res/images/splash_testnet.png

RES_MOVIES = $(wildcard res/movies/spinner-*.png)

PLATINUMCOIN_RC = res/platinumcoin-qt-res.rc

libplatinumcoinqt_a_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms $(QT_DBUS_INCLUDES)
libplatinumcoinqt_a_SOURCES = $(PLATINUMCOIN_QT_CPP) $(PLATINUMCOIN_QT_H) $(QT_FORMS_UI) \
  $(QT_QRC) $(QT_TS) $(PROTOBUF_PROTO) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES)

nodist_libplatinumcoinqt_a_SOURCES = $(QT_MOC_CPP) $(QT_MOC) $(PROTOBUF_CC) \
  $(PROTOBUF_H) $(QT_QRC_CPP)

BUILT_SOURCES = $(nodist_libplatinumcoinqt_a_SOURCES)

#Generating these with a half-written protobuf header leads to wacky results.
#This makes sure it's done.
$(QT_MOC): $(PROTOBUF_H)
$(QT_MOC_CPP): $(PROTOBUF_H)

# platinumcoin-qt binary #
platinumcoin_qt_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms
platinumcoin_qt_SOURCES = platinumcoin.cpp
if TARGET_DARWIN
  platinumcoin_qt_SOURCES += $(PLATINUMCOIN_MM)
endif
if TARGET_WINDOWS
  platinumcoin_qt_SOURCES += $(PLATINUMCOIN_RC)
endif
platinumcoin_qt_LDADD = libplatinumcoinqt.a $(LIBPLATINUMCOIN_SERVER)
if ENABLE_WALLET
platinumcoin_qt_LDADD += $(LIBPLATINUMCOIN_WALLET)
endif
platinumcoin_qt_LDADD += $(LIBPLATINUMCOIN_CLI) $(LIBPLATINUMCOIN_COMMON) $(LIBLEVELDB) $(LIBMEMENV) \
  $(BOOST_LIBS) $(QT_LIBS) $(QT_DBUS_LIBS) $(QR_LIBS) $(PROTOBUF_LIBS) $(BDB_LIBS)
platinumcoin_qt_LDFLAGS = $(QT_LDFLAGS)

# forms/foo.h -> forms/ui_foo.h
QT_FORMS_H=$(join $(dir $(QT_FORMS_UI)),$(addprefix ui_, $(notdir $(QT_FORMS_UI:.ui=.h))))

#locale/foo.ts -> locale/foo.qm
QT_QM=$(QT_TS:.ts=.qm)

.PHONY: FORCE
.SECONDARY: $(QT_QM)

platinumcoinstrings.cpp: FORCE
	$(MAKE) -C $(top_srcdir)/src qt/platinumcoinstrings.cpp

translate: platinumcoinstrings.cpp $(QT_FORMS_UI) $(QT_FORMS_UI) $(PLATINUMCOIN_QT_CPP) $(PLATINUMCOIN_QT_H) $(PLATINUMCOIN_MM)
	@test -n $(LUPDATE) || echo "lupdate is required for updating translations"
	@QT_SELECT=$(QT_SELECT) $(LUPDATE) $^ -locations relative -no-obsolete -ts locale/platinumcoin_en.ts

$(QT_QRC_CPP): $(QT_QRC) $(QT_QM) $(QT_FORMS_H) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES) $(PROTOBUF_H)
	@cd $(abs_srcdir); test -f $(RCC) && QT_SELECT=$(QT_SELECT) $(RCC) -name platinumcoin -o $(abs_builddir)/$@ $< || \
	  echo error: could not build $@
	$(SED) -i.bak -e '/^\*\*.*Created:/d' $@ && rm $@.bak
	$(SED) -i.bak -e '/^\*\*.*by:/d' $@ && rm $@.bak

CLEANFILES = $(BUILT_SOURCES) $(QT_QM) $(QT_FORMS_H) *.gcda *.gcno
