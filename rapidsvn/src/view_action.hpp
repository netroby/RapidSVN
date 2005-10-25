/*
 * ====================================================================
 * Copyright (c) 2002-2005 The RapidSvn Group.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program (in the file GPL.txt); if not, write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 *
 * This software consists of voluntary contributions made by many
 * individuals.  For exact contribution history, see the revision
 * history and logs, available at http://rapidsvn.tigris.org/.
 * ====================================================================
 */
#ifndef _VIEW_ACTION_H_INCLUDED_
#define _VIEW_ACTION_H_INCLUDED_

// app
#include "action.hpp"
#include "get_data.hpp"

// forward declarations
class wxWindow;

/**
 * This action downloads a specific revision 
 * of a file (specified in @a GetData) and 
 * displays the file
 */
class ViewAction:public Action
{
public:
  /**
   * Constructor. This constructor creates an
   * action, that will not prompt for
   * input in Prepare. Instead, the settings
   * in @a data will be used
   *
   * @param parent parent window
   * @param title title of the action
   * @param data update data
   */
  ViewAction (wxWindow * parent,
              const GetData & data);

  /**
   * Constructor. 
   * An editor for the target will be called.
   */
  ViewAction (wxWindow * parent);


  virtual bool Perform ();
  virtual bool Prepare ();

  /**
   * Describe which targets the action can perform upon
   * when viewing a file
   */
  static unsigned int GetViewFlags ()
  {
    return DONT_UPDATE|WITHOUT_TARGET;
  }

  /**
   * Describe which targets the action can perform upon
   * when editing a file
   */
  static unsigned int GetEditFlags ()
  {
    return SINGLE_TARGET|UPDATE_LATER|VERSIONED_WC_TYPE;
  }

private:
  bool m_edit;
  GetData m_data;
};

#endif
/* -----------------------------------------------------------------
 * local variables:
 * eval: (load-file "../rapidsvn-dev.el")
 * end:
 */