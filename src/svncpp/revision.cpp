/*
 * ====================================================================
 * Copyright (c) 2002 The RapidSvn Group.  All rights reserved.
 *
 * This software is licensed as described in the file LICENSE.txt,
 * which you should have received as part of this distribution.
 *
 * This software consists of voluntary contributions made by many
 * individuals.  For exact contribution history, see the revision
 * history and logs, available at http://rapidsvn.tigris.org/.
 * ====================================================================
 */

#include "revision.hpp"

namespace svn
{
  Revision::Revision (const svn_opt_revision_t revision)
  {
    init (revision);
  }

  Revision::Revision (const svn_revnum_t revnum)
  {
    m_revision.kind = svn_opt_revision_number;
    m_revision.value.number = revnum;
  }

  Revision::Revision (const svn_opt_revision_kind kind)
  {
    m_revision.kind = kind;
    m_revision.value.number = 0;
  }

  Revision::Revision (const apr_time_t date)
  {
    m_revision.kind = svn_opt_revision_date;
    m_revision.value.date = date;
  }

  Revision::Revision (const Revision & revision)
  {
    init (revision.revision ());
  }

  void
  Revision::init (const svn_opt_revision_t revision)
  {
    m_revision.kind = revision.kind;

    // m_revision.value is a union so we are not
    // allowed to set number if we want to use date
    // and vice versa

    switch( revision.kind )
    {
    case svn_opt_revision_number:
      m_revision.value.number = revision.value.number;
      break;

    case svn_opt_revision_date:
      m_revision.value.date = revision.value.date;
      break;

    default:
      m_revision.value.number = 0;
    }
  }

  const svn_opt_revision_t
  Revision::revision () const
  {
    return m_revision;
  }

  const svn_revnum_t
  Revision::revnum () const
  {
    return m_revision.value.number;
  }

  const apr_time_t
  Revision::date () const
  {
    return m_revision.value.date;
  }

  const svn_opt_revision_kind
  Revision::kind () const
  {
    return m_revision.kind;
  }
}

/* -----------------------------------------------------------------
 * local variables:
 * eval: (load-file "../../rapidsvn-dev.el")
 * end:
 */