/*
 * ====================================================================
 * Copyright (c) 2002-2004 The RapidSvn Group.  All rights reserved.
 *
 * This software is licensed as described in the file LICENSE.txt,
 * which you should have received as part of this distribution.
 *
 * This software consists of voluntary contributions made by many
 * individuals.  For exact contribution history, see the revision
 * history and logs, available at http://rapidsvn.tigris.org/.
 * ====================================================================
 */
#ifndef _RAPIDSVN_VERSION_H_INCLUDED_
#define _RAPIDSVN_VERSION_H_INCLUDED_

#define APPLICATION_NAME _("RapidSVN")

#define RAPIDSVN_COPYRIGHT "(C) 2002-2004 The RapidSvn Group. All rights reserved."

/* Symbols that define the version number.
 * The numbers are maintained in the file version.xml (in the
 * main project directory). Before creating a release, you should
 * run <main project directiry>/tools/check-version.py to make
 * sure all the places with version information are updated.
 */

/* Version numbers: <major>.<minor>.<micro>-<release> */

/* Major version number.
   Modify when incompatible changes are made to published interfaces. */
#define RAPIDSVN_VER_MAJOR 0

/* Minor version number.
   Modify when new functionality is added or new interfaces are
   defined, but all changes are backward compatible. */
#define RAPIDSVN_VER_MINOR 7

/* Patch number.
   Modify for every released patch. */
#define RAPIDSVN_VER_MICRO 1

/* Symbolic name of the milestone
   Modify whenever Minor number is changed. */
#define RAPIDSVN_VER_MILESTONE "0.7.1"

#endif
/* -----------------------------------------------------------------
 * local variables:
 * eval: (load-file "../rapidsvn-dev.el")
 * end:
 */
