#!/bin/bash
echo "Executing the configure script for SPBR..."
echo " "
kvsmake -g sopbr_tmp
echo "Makefile.kvs is created."
echo " "
echo "Edit INSTALL_DIR in Makefile if necessary:"
echo "  INSTALL_DIR=\$(HOME)/local/bin"
