EXTRA_DIST = osmoggsn-usermanual.adoc \
    osmoggsn-usermanual-docinfo.xml \
    osmoggsn-vty-reference.xml \
    chapters \
    vty

if BUILD_MANUALS
  ASCIIDOC = osmoggsn-usermanual.adoc
  ASCIIDOC_DEPS = $(srcdir)/chapters/*.adoc
  include $(OSMO_GSM_MANUALS_DIR)/build/Makefile.asciidoc.inc

  VTY_REFERENCE = osmoggsn-vty-reference.xml
  include $(OSMO_GSM_MANUALS_DIR)/build/Makefile.vty-reference.inc

  include $(OSMO_GSM_MANUALS_DIR)/build/Makefile.common.inc
endif
