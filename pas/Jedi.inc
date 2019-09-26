{******************************************************************************}
{                                                                              }
{ The contents of this file are subject to the Mozilla Public License Version  }
{ 1.1 (the "License"); you may not use this file except in compliance with the }
{ License. You may obtain a copy of the License at http://www.mozilla.org/MPL/ }
{                                                                              }
{ Software distributed under the License is distributed on an "AS IS" basis,   }
{ WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License for }
{ the specific language governing rights and limitations under the License.    }
{                                                                              }
{ The Original Code is JEDI.INC.                                               }
{                                                                              }
{ The Initial Developer of the Original Code is Project JEDI                   }
{ http://www.delphi-jedi.org                                                   }
{                                                                              }
{******************************************************************************}
{                                                                              }
{ This file defines various generic compiler directives used in the JEDI Code  }
{ Library (JCL) and JEDI Visual Component Library Library (J-VCL). The         }
{ directives in this file are of generic nature and consist mostly of mappings }
{ from the VERXXX directives defined by Delphi and C++ Builder to friendly     }
{ names such as DELPHI5 and SUPPORTS_WIDESTRING. These friendly names are      }
{ subsequently used in both libraries to test for compiler versions and/or     }
{ whether the compiler supports certain features (such as widestring's or 64   }
{ bit integers. Both libraries provide an additional, library specific,        }
{ include file. For the JCL this is JCL.INC. These files should be included in }
{ source files instead of this file (which is pulled in automatically).        }
{                                                                              }
{ Maintainer: Marcel van Brakel                                                }
{ Last modified: May  25, 2002                                                 }
{                                                                              }
{******************************************************************************}

(*

- Development environment directives

  This file defines two driectives to indicate which development environment the
  library is being compiled with. Currently this can either be Delphi or
  C++ Builder (in the near future "Kylix" will be added).

  Directive    Description
  ------------------------------------------------------------------------------
  DELPHI       Defined if compiled with Delphi
  BCB          Defined if compiled with C++ Builder

- Platform Directives

  Platform directives are not explicitly defined in this file but are defined
  by the compiler itself. They are listed here only for completeness.

  Directive    Description
  ------------------------------------------------------------------------------
  WIN32        Defined when target platform is 32 bit Windows
  LINUX        Defined when target platform is Linux

- Delphi Versions

  The following directives are direct mappings from the VERXXX directives to a
  friendly name of the associated compiler. These directives are only defined if
  the compiler is Delphi (ie DELPHI is defined).

  Directive    Description
  ------------------------------------------------------------------------------
  DELPHI1      Defined when compiling with Delphi 1
  DELPHI2      Defined when compiling with Delphi 2
  DELPHI3      Defined when compiling with Delphi 3
  DELPHI4      Defined when compiling with Delphi 4
  DELPHI5      Defined when compiling with Delphi 5
  DELPHI6      Defined when compiling with Delphi 6
  DELPHI1_UP   Defined when compiling with Delphi 1 or higher
  DELPHI2_UP   Defined when compiling with Delphi 2 or higher
  DELPHI3_UP   Defined when compiling with Delphi 3 or higher
  DELPHI4_UP   Defined when compiling with Delphi 4 or higher
  DELPHI5_UP   Defined when compiling with Delphi 5 or higher
  DELPHI6_UP   Defined when compiling with Delphi 6 or higher
  DELPHI7_UP   Defined when compiling with Delphi 7 or higher
  ...

- C++ Builder Versions

  The following directives are direct mappings from the VERXXX directives to a
  friendly name of the associated compiler. These directives are only defined if
  the compiler is C++ Builder (ie BCB is defined).

  Directive    Description
  ------------------------------------------------------------------------------
  BCB1         Defined when compiling with C++ Builder 1
  BCB3         Defined when compiling with C++ Builder 3
  BCB4         Defined when compiling with C++ Builder 4
  BCB5         Defined when compiling with C++ Builder 5
  BCB6         Defined when compiling with C++ Builder 6
  BCB7         Defined when compiling with C++ Builder 7
  BCB1_UP      Defined when compiling with C++ Builder 1 or higher
  BCB3_UP      Defined when compiling with C++ Builder 3 or higher
  BCB4_UP      Defined when compiling with C++ Builder 4 or higher
  BCB5_UP      Defined when compiling with C++ Builder 5 or higher
  BCB6_UP      Defined when compiling with C++ Builder 6 or higher
  BCB7_UP      Defined when compiling with C++ Builder 7 or higher
  ...

- Product Versions
  (not "Compiler Versions")

  The following directives are direct mappings from the VERXXX directives to a
  friendly name of the associated products. Unlike the DELPHI_X and BCB_X
  directives, these directives are indepedent of the development environment.
  That is, they are defined regardless of whether compilation takes place using
  Delphi or C++ Builder.

  Directive    Description
  ------------------------------------------------------------------------------
  COMPILER1    Defined when compiling with Delphi 1
  COMPILER2    Defined when compiling with Delphi 2 or C++ Builder 1
  COMPILER3    Defined when compiling with Delphi 3
  COMPILER35   Defined when compiling with C++ Builder 3
  COMPILER4    Defined when compiling with Delphi 4 or C++ Builder 4
  COMPILER5    Defined when compiling with Delphi 5 or C++ Builder 5
  COMPILER6    Defined when compiling with Delphi 6 or C++ Builder 6
  COMPILER1_UP Defined when compiling with Delphi 1 or higher
  COMPILER2_UP Defined when compiling with Delphi 2 or C++ Builder 1 or higher
  COMPILER3_UP Defined when compiling with Delphi 3 or higher
  COMPILER35_UP Defined when compiling with C++ Builder 3 or higher
  COMPILER4_UP Defined when compiling with Delphi 4 or C++ Builder 4 or higher
  COMPILER5_UP Defined when compiling with Delphi 5 or C++ Builder 5 or higher
  COMPILER6_UP Defined when compiling with Delphi 6 or C++ Builder 6 or higher
  COMPILER7_UP Defined when compiling with Delphi 7 or C++ Builder 7 or higher
  ...

- Feature Directives

  The features directives are used to test if the compiler supports specific
  features, such as method overloading, and adjust the sources accordingly. Use
  of these directives is preferred over the use of the DELPHI and COMPILER
  directives.

  Directive              Description
  ------------------------------------------------------------------------------
  SUPPORTS_WIDESTRING    Compiler supports the WideString type (D3/BCB3 up)
  SUPPORTS_INTERFACE     Compiler supports interfaces (D3/BCB3)
  SUPPORTS_EXTSYM        Compiler supports the $EXTERNALSYM directive (D4/BCB3)
  SUPPORTS_NODEFINE      Compiler supports the $NODEFINE directive (D4/BCB3)
  SUPPORTS_INT64         Compiler supports the Int64 type (D4/BCB4)
  SUPPORTS_DYNAMICARRAYS Compiler supports dynamic arrays (D4/BCB4)
  SUPPORTS_DEFAULTPARAMS Compiler supports default parameters (D4/BCB4)
  SUPPORTS_OVERLOAD      Compiler supports overloading (D4/BCB4)

- Compiler Settings

  The compiler settings directives indicate whether a specific compiler setting
  is in effect. This facilitates changing compiler settings locally in a more
  compact and readible manner.

  Directive              Description
  ------------------------------------------------------------------------------
  ALIGN_ON               Compiling in the A+ state (no alignment)
  BOOLEVAL_ON            Compiling in the B+ state (complete boolean evaluation)
  ASSERTIONS_ON          Compiling in the C+ state (assertions on)
  DEBUGINFO_ON           Compiling in the D+ state (debug info generation on)
  IMPORTEDDATA_ON        Compiling in the G+ state (creation of imported data references)
  LONGSTRINGS_ON         Compiling in the H+ state (string defined as AnsiString)
  IOCHECKS_ON            Compiling in the I+ state (I/O checking enabled)
  WRITEABLECONST_ON      Compiling in the J+ state (typed constants can be modified)
  LOCALSYMBOLS           Compiling in the L+ state (local symbol generation)
  TYPEINFO_ON            Compiling in the M+ state (RTTI generation on)
  OPTIMIZATION_ON        Compiling in the O+ state (code optimization on)
  OPENSTRINGS_ON         Compiling in the P+ state (variable string parameters are openstrings)
  OVERFLOWCHECKS_ON      Compiling in the Q+ state (overflow checing on)
  RANGECHECKS_ON         Compiling in the R+ state (range checking on)
  TYPEDADDRESS_ON        Compiling in the T+ state (pointers obtained using the @ operator are typed)
  SAFEDIVIDE_ON          Compiling in the U+ state (save FDIV instruction through RTL emulation)
  VARSTRINGCHECKS_ON     Compiling in the V+ state (type checking of shortstrings)
  STACKFRAMES_ON         Compiling in the W+ state (generation of stack frames)
  EXTENDEDSYNTAX_ON      Compiling in the X+ state (Delphi extended syntax enabled)

*)

//------------------------------------------------------------------------------
// Compiler settings
//------------------------------------------------------------------------------

{$IFOPT A+} {$DEFINE ALIGN_ON} {$ENDIF}
{$IFOPT B+} {$DEFINE BOOLEVAL_ON} {$ENDIF}
{$IFOPT C+} {$DEFINE ASSERTIONS_ON} {$ENDIF}
{$IFOPT D+} {$DEFINE DEBUGINFO_ON} {$ENDIF}
{$IFOPT G+} {$DEFINE IMPORTEDDATA_ON} {$ENDIF}
{$IFOPT H+} {$DEFINE LONGSTRINGS_ON} {$ENDIF}
//HINTS
{$IFOPT I+} {$DEFINE IOCHECKS_ON} {$ENDIF}
{$IFOPT J+} {$DEFINE WRITEABLECONST_ON} {$ENDIF}
{$IFOPT L+} {$DEFINE LOCALSYMBOLS} {$ENDIF}
{$IFOPT M+} {$DEFINE TYPEINFO_ON} {$ENDIF}
{$IFOPT O+} {$DEFINE OPTIMIZATION_ON} {$ENDIF}
{$IFOPT P+} {$DEFINE OPENSTRINGS_ON} {$ENDIF}
{$IFOPT Q+} {$DEFINE OVERFLOWCHECKS_ON} {$ENDIF}
{$IFOPT R+} {$DEFINE RANGECHECKS_ON} {$ENDIF}
//REALCOMPATIBILITY
{$IFOPT T+} {$DEFINE TYPEDADDRESS_ON} {$ENDIF}
{$IFOPT U+} {$DEFINE SAFEDIVIDE_ON} {$ENDIF}
{$IFOPT V+} {$DEFINE VARSTRINGCHECKS_ON} {$ENDIF}
{$IFOPT W+} {$DEFINE STACKFRAMES_ON} {$ENDIF}
//WARNINGS
{$IFOPT X+} {$DEFINE EXTENDEDSYNTAX_ON} {$ENDIF}

//------------------------------------------------------------------------------
// VERXXX to COMPILERX, DELPHIX and BCBX mappings
//------------------------------------------------------------------------------

// Delphi 10.3 Rio
{$IFDEF VER330}
  {$DEFINE COMPILER26}
  {$IFDEF BCB}
    {$DEFINE BCB26}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI26}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi 10.2 Tokyo
{$IFDEF VER320}
  {$DEFINE COMPILER25}
  {$IFDEF BCB}
    {$DEFINE BCB25}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI25}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi 10.2 Berlin
{$IFDEF VER310}
  {$DEFINE COMPILER24}
  {$IFDEF BCB}
    {$DEFINE BCB24}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI24}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi 10 Seattle
{$IFDEF VER300}
  {$DEFINE COMPILER23}
  {$IFDEF BCB}
    {$DEFINE BCB23}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI23}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi XE8
{$IFDEF VER280}
  {$DEFINE COMPILER22}
  {$IFDEF BCB}
    {$DEFINE BCB22}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI22}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi XE7
{$IFDEF VER270}
  {$DEFINE COMPILER21}
  {$IFDEF BCB}
    {$DEFINE BCB21}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI21}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi XE6
{$IFDEF VER270}
  {$DEFINE COMPILER20}
  {$IFDEF BCB}
    {$DEFINE BCB20}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI20}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi XE5
{$IFDEF VER260}
  {$DEFINE COMPILER19}
  {$IFDEF BCB}
    {$DEFINE BCB19}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI19}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi XE4
{$IFDEF VER250}
  {$DEFINE COMPILER18}
  {$IFDEF BCB}
    {$DEFINE BCB18}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI18}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi XE3
{$IFDEF VER240}
  {$DEFINE COMPILER17}
  {$IFDEF BCB}
    {$DEFINE BCB17}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI17}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi XE2
{$IFDEF VER230}
  {$DEFINE COMPILER16}
  {$IFDEF BCB}
    {$DEFINE BCB16}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI16}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi XE
{$IFDEF VER220}
  {$DEFINE COMPILER15}
  {$IFDEF BCB}
    {$DEFINE BCB15}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI15}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi 2010
{$IFDEF VER210}
  {$DEFINE COMPILER14}
  {$IFDEF BCB}
    {$DEFINE BCB14}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI14}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi 2009
{$IFDEF VER200}
  {$DEFINE COMPILER12}
  {$IFDEF BCB}
    {$DEFINE BCB12}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI12}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi 2007 for .Net
{$IFDEF VER190}
  {$DEFINE COMPILER11}
  {$IFDEF BCB}
    {$DEFINE BCB11}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI11}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi 2007
{$IFDEF VER185}
  {$DEFINE COMPILER11}
  {$IFDEF BCB}
    {$DEFINE BCB11}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI11}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi 2006
{$IFDEF VER180}
  {$DEFINE COMPILER10}
  {$IFDEF BCB}
    {$DEFINE BCB10}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI10}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi 2005
{$IFDEF VER170}
  {$DEFINE COMPILER9}
  {$IFDEF BCB}
    {$DEFINE BCB9}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI9}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

// Delphi 8 for .Net
{$IFDEF VER160}
  {$DEFINE COMPILER8}
  {$IFDEF BCB}
    {$DEFINE BCB8}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI8}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

{$IFDEF VER150}
  {$DEFINE COMPILER7}
  {$IFDEF BCB}
    {$DEFINE BCB7}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI7}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

{$IFDEF VER140}
  {$DEFINE COMPILER6}
  {$IFDEF BCB}
    {$DEFINE BCB6}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI6}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

{$IFDEF VER130}
  {$DEFINE COMPILER5}
  {$IFDEF BCB}
    {$DEFINE BCB5}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI5}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

{$IFDEF VER125}
  {$DEFINE COMPILER4}
  {$DEFINE BCB4}
  {$DEFINE BCB}
{$ENDIF}

{$IFDEF VER120}
  {$DEFINE COMPILER4}
  {$DEFINE DELPHI4}
  {$DEFINE DELPHI}
{$ENDIF}

{$IFDEF VER110}
  {$DEFINE COMPILER35}
  {$DEFINE BCB3}
{$ENDIF}

{$IFDEF VER100}
  {$DEFINE COMPILER3}
  {$DEFINE DELPHI3}
  {$DEFINE DELPHI}
{$ENDIF}

{$IFDEF VER93}
  {$DEFINE COMPILER2}
  {$DEFINE BCB1}
  {$DEFINE BCB}
{$ENDIF}

{$IFDEF VER90}
  {$DEFINE COMPILER2}
  {$DEFINE DELPHI2}
  {$DEFINE DELPHI}
{$ENDIF}

{$IFDEF VER80}
  {$DEFINE COMPILER1}
  {$DEFINE DELPHI1}
  {$DEFINE DELPHI}
{$ENDIF}

//------------------------------------------------------------------------------
// DELPHIX_UP from DELPHIX mappings
//------------------------------------------------------------------------------

{$IFDEF DELPHI26}
  {$DEFINE DELPHI26_UP}
  {$DEFINE DELPHI25_UP}
  {$DEFINE DELPHI24_UP}
  {$DEFINE DELPHI23_UP}
  {$DEFINE DELPHI22_UP}
  {$DEFINE DELPHI21_UP}
  {$DEFINE DELPHI20_UP}
  {$DEFINE DELPHI19_UP}
  {$DEFINE DELPHI18_UP}
  {$DEFINE DELPHI17_UP}
  {$DEFINE DELPHI16_UP}
  {$DEFINE DELPHI15_UP}
  {$DEFINE DELPHI14_UP}
  {$DEFINE DELPHI13_UP}
  {$DEFINE DELPHI12_UP}
  {$DEFINE DELPHI11_UP}
  {$DEFINE DELPHI10_UP}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI25}
  {$DEFINE DELPHI25_UP}
  {$DEFINE DELPHI24_UP}
  {$DEFINE DELPHI23_UP}
  {$DEFINE DELPHI22_UP}
  {$DEFINE DELPHI21_UP}
  {$DEFINE DELPHI20_UP}
  {$DEFINE DELPHI19_UP}
  {$DEFINE DELPHI18_UP}
  {$DEFINE DELPHI17_UP}
  {$DEFINE DELPHI16_UP}
  {$DEFINE DELPHI15_UP}
  {$DEFINE DELPHI14_UP}
  {$DEFINE DELPHI13_UP}
  {$DEFINE DELPHI12_UP}
  {$DEFINE DELPHI11_UP}
  {$DEFINE DELPHI10_UP}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI24}
  {$DEFINE DELPHI24_UP}
  {$DEFINE DELPHI23_UP}
  {$DEFINE DELPHI22_UP}
  {$DEFINE DELPHI21_UP}
  {$DEFINE DELPHI20_UP}
  {$DEFINE DELPHI19_UP}
  {$DEFINE DELPHI18_UP}
  {$DEFINE DELPHI17_UP}
  {$DEFINE DELPHI16_UP}
  {$DEFINE DELPHI15_UP}
  {$DEFINE DELPHI14_UP}
  {$DEFINE DELPHI13_UP}
  {$DEFINE DELPHI12_UP}
  {$DEFINE DELPHI11_UP}
  {$DEFINE DELPHI10_UP}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI23}
  {$DEFINE DELPHI23_UP}
  {$DEFINE DELPHI22_UP}
  {$DEFINE DELPHI21_UP}
  {$DEFINE DELPHI20_UP}
  {$DEFINE DELPHI19_UP}
  {$DEFINE DELPHI18_UP}
  {$DEFINE DELPHI17_UP}
  {$DEFINE DELPHI16_UP}
  {$DEFINE DELPHI15_UP}
  {$DEFINE DELPHI14_UP}
  {$DEFINE DELPHI13_UP}
  {$DEFINE DELPHI12_UP}
  {$DEFINE DELPHI11_UP}
  {$DEFINE DELPHI10_UP}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI22}
  {$DEFINE DELPHI22_UP}
  {$DEFINE DELPHI21_UP}
  {$DEFINE DELPHI20_UP}
  {$DEFINE DELPHI19_UP}
  {$DEFINE DELPHI18_UP}
  {$DEFINE DELPHI17_UP}
  {$DEFINE DELPHI16_UP}
  {$DEFINE DELPHI15_UP}
  {$DEFINE DELPHI14_UP}
  {$DEFINE DELPHI13_UP}
  {$DEFINE DELPHI12_UP}
  {$DEFINE DELPHI11_UP}
  {$DEFINE DELPHI10_UP}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI21}
  {$DEFINE DELPHI21_UP}
  {$DEFINE DELPHI20_UP}
  {$DEFINE DELPHI19_UP}
  {$DEFINE DELPHI18_UP}
  {$DEFINE DELPHI17_UP}
  {$DEFINE DELPHI16_UP}
  {$DEFINE DELPHI15_UP}
  {$DEFINE DELPHI14_UP}
  {$DEFINE DELPHI13_UP}
  {$DEFINE DELPHI12_UP}
  {$DEFINE DELPHI11_UP}
  {$DEFINE DELPHI10_UP}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI20}
  {$DEFINE DELPHI20_UP}
  {$DEFINE DELPHI19_UP}
  {$DEFINE DELPHI18_UP}
  {$DEFINE DELPHI17_UP}
  {$DEFINE DELPHI16_UP}
  {$DEFINE DELPHI15_UP}
  {$DEFINE DELPHI14_UP}
  {$DEFINE DELPHI13_UP}
  {$DEFINE DELPHI12_UP}
  {$DEFINE DELPHI11_UP}
  {$DEFINE DELPHI10_UP}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI19}
  {$DEFINE DELPHI19_UP}
  {$DEFINE DELPHI18_UP}
  {$DEFINE DELPHI17_UP}
  {$DEFINE DELPHI16_UP}
  {$DEFINE DELPHI15_UP}
  {$DEFINE DELPHI14_UP}
  {$DEFINE DELPHI13_UP}
  {$DEFINE DELPHI12_UP}
  {$DEFINE DELPHI11_UP}
  {$DEFINE DELPHI10_UP}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI18}
  {$DEFINE DELPHI18_UP}
  {$DEFINE DELPHI17_UP}
  {$DEFINE DELPHI16_UP}
  {$DEFINE DELPHI15_UP}
  {$DEFINE DELPHI14_UP}
  {$DEFINE DELPHI13_UP}
  {$DEFINE DELPHI12_UP}
  {$DEFINE DELPHI11_UP}
  {$DEFINE DELPHI10_UP}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI17}
  {$DEFINE DELPHI17_UP}
  {$DEFINE DELPHI16_UP}
  {$DEFINE DELPHI15_UP}
  {$DEFINE DELPHI14_UP}
  {$DEFINE DELPHI13_UP}
  {$DEFINE DELPHI12_UP}
  {$DEFINE DELPHI11_UP}
  {$DEFINE DELPHI10_UP}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI16}
  {$DEFINE DELPHI16_UP}
  {$DEFINE DELPHI15_UP}
  {$DEFINE DELPHI14_UP}
  {$DEFINE DELPHI13_UP}
  {$DEFINE DELPHI12_UP}
  {$DEFINE DELPHI11_UP}
  {$DEFINE DELPHI10_UP}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI15}
  {$DEFINE DELPHI15_UP}
  {$DEFINE DELPHI14_UP}
  {$DEFINE DELPHI13_UP}
  {$DEFINE DELPHI12_UP}
  {$DEFINE DELPHI11_UP}
  {$DEFINE DELPHI10_UP}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI14}
  {$DEFINE DELPHI14_UP}
  {$DEFINE DELPHI13_UP}
  {$DEFINE DELPHI12_UP}
  {$DEFINE DELPHI11_UP}
  {$DEFINE DELPHI10_UP}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI13}
  {$DEFINE DELPHI13_UP}
  {$DEFINE DELPHI12_UP}
  {$DEFINE DELPHI11_UP}
  {$DEFINE DELPHI10_UP}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI12}
  {$DEFINE DELPHI12_UP}
  {$DEFINE DELPHI11_UP}
  {$DEFINE DELPHI10_UP}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI11}
  {$DEFINE DELPHI11_UP}
  {$DEFINE DELPHI10_UP}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI10}
  {$DEFINE DELPHI10_UP}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI9}
  {$DEFINE DELPHI9_UP}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI8}
  {$DEFINE DELPHI8_UP}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI7}
  {$DEFINE DELPHI7_UP}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI6}
  {$DEFINE DELPHI6_UP}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI5}
  {$DEFINE DELPHI5_UP}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI4}
  {$DEFINE DELPHI4_UP}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI3}
  {$DEFINE DELPHI3_UP}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI2}
  {$DEFINE DELPHI2_UP}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

{$IFDEF DELPHI1}
  {$DEFINE DELPHI1_UP}
{$ENDIF}

//------------------------------------------------------------------------------
// BCBX_UP from BCBX mappings
//------------------------------------------------------------------------------

{$IFDEF BCB26}
  {$DEFINE BCB26_UP}
  {$DEFINE BCB24_UP}
  {$DEFINE BCB23_UP}
  {$DEFINE BCB22_UP}
  {$DEFINE BCB21_UP}
  {$DEFINE BCB20_UP}
  {$DEFINE BCB19_UP}
  {$DEFINE BCB18_UP}
  {$DEFINE BCB17_UP}
  {$DEFINE BCB16_UP}
  {$DEFINE BCB15_UP}
  {$DEFINE BCB14_UP}
  {$DEFINE BCB13_UP}
  {$DEFINE BCB12_UP}
  {$DEFINE BCB11_UP}
  {$DEFINE BCB10_UP}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB25}
  {$DEFINE BCB25_UP}
  {$DEFINE BCB24_UP}
  {$DEFINE BCB23_UP}
  {$DEFINE BCB22_UP}
  {$DEFINE BCB21_UP}
  {$DEFINE BCB20_UP}
  {$DEFINE BCB19_UP}
  {$DEFINE BCB18_UP}
  {$DEFINE BCB17_UP}
  {$DEFINE BCB16_UP}
  {$DEFINE BCB15_UP}
  {$DEFINE BCB14_UP}
  {$DEFINE BCB13_UP}
  {$DEFINE BCB12_UP}
  {$DEFINE BCB11_UP}
  {$DEFINE BCB10_UP}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB24}
  {$DEFINE BCB24_UP}
  {$DEFINE BCB23_UP}
  {$DEFINE BCB22_UP}
  {$DEFINE BCB21_UP}
  {$DEFINE BCB20_UP}
  {$DEFINE BCB19_UP}
  {$DEFINE BCB18_UP}
  {$DEFINE BCB17_UP}
  {$DEFINE BCB16_UP}
  {$DEFINE BCB15_UP}
  {$DEFINE BCB14_UP}
  {$DEFINE BCB13_UP}
  {$DEFINE BCB12_UP}
  {$DEFINE BCB11_UP}
  {$DEFINE BCB10_UP}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB23}
  {$DEFINE BCB23_UP}
  {$DEFINE BCB22_UP}
  {$DEFINE BCB21_UP}
  {$DEFINE BCB20_UP}
  {$DEFINE BCB19_UP}
  {$DEFINE BCB18_UP}
  {$DEFINE BCB17_UP}
  {$DEFINE BCB16_UP}
  {$DEFINE BCB15_UP}
  {$DEFINE BCB14_UP}
  {$DEFINE BCB13_UP}
  {$DEFINE BCB12_UP}
  {$DEFINE BCB11_UP}
  {$DEFINE BCB10_UP}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB22}
  {$DEFINE BCB22_UP}
  {$DEFINE BCB21_UP}
  {$DEFINE BCB20_UP}
  {$DEFINE BCB19_UP}
  {$DEFINE BCB18_UP}
  {$DEFINE BCB17_UP}
  {$DEFINE BCB16_UP}
  {$DEFINE BCB15_UP}
  {$DEFINE BCB14_UP}
  {$DEFINE BCB13_UP}
  {$DEFINE BCB12_UP}
  {$DEFINE BCB11_UP}
  {$DEFINE BCB10_UP}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB21}
  {$DEFINE BCB21_UP}
  {$DEFINE BCB20_UP}
  {$DEFINE BCB19_UP}
  {$DEFINE BCB18_UP}
  {$DEFINE BCB17_UP}
  {$DEFINE BCB16_UP}
  {$DEFINE BCB15_UP}
  {$DEFINE BCB14_UP}
  {$DEFINE BCB13_UP}
  {$DEFINE BCB12_UP}
  {$DEFINE BCB11_UP}
  {$DEFINE BCB10_UP}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB20}
  {$DEFINE BCB20_UP}
  {$DEFINE BCB19_UP}
  {$DEFINE BCB18_UP}
  {$DEFINE BCB17_UP}
  {$DEFINE BCB16_UP}
  {$DEFINE BCB15_UP}
  {$DEFINE BCB14_UP}
  {$DEFINE BCB13_UP}
  {$DEFINE BCB12_UP}
  {$DEFINE BCB11_UP}
  {$DEFINE BCB10_UP}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB19}
  {$DEFINE BCB19_UP}
  {$DEFINE BCB18_UP}
  {$DEFINE BCB17_UP}
  {$DEFINE BCB16_UP}
  {$DEFINE BCB15_UP}
  {$DEFINE BCB14_UP}
  {$DEFINE BCB13_UP}
  {$DEFINE BCB12_UP}
  {$DEFINE BCB11_UP}
  {$DEFINE BCB10_UP}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB18}
  {$DEFINE BCB18_UP}
  {$DEFINE BCB17_UP}
  {$DEFINE BCB16_UP}
  {$DEFINE BCB15_UP}
  {$DEFINE BCB14_UP}
  {$DEFINE BCB13_UP}
  {$DEFINE BCB12_UP}
  {$DEFINE BCB11_UP}
  {$DEFINE BCB10_UP}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB17}
  {$DEFINE BCB17_UP}
  {$DEFINE BCB16_UP}
  {$DEFINE BCB15_UP}
  {$DEFINE BCB14_UP}
  {$DEFINE BCB13_UP}
  {$DEFINE BCB12_UP}
  {$DEFINE BCB11_UP}
  {$DEFINE BCB10_UP}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB16}
  {$DEFINE BCB16_UP}
  {$DEFINE BCB15_UP}
  {$DEFINE BCB14_UP}
  {$DEFINE BCB13_UP}
  {$DEFINE BCB12_UP}
  {$DEFINE BCB11_UP}
  {$DEFINE BCB10_UP}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB15}
  {$DEFINE BCB15_UP}
  {$DEFINE BCB14_UP}
  {$DEFINE BCB13_UP}
  {$DEFINE BCB12_UP}
  {$DEFINE BCB11_UP}
  {$DEFINE BCB10_UP}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB14}
  {$DEFINE BCB14_UP}
  {$DEFINE BCB13_UP}
  {$DEFINE BCB12_UP}
  {$DEFINE BCB11_UP}
  {$DEFINE BCB10_UP}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB13}
  {$DEFINE BCB13_UP}
  {$DEFINE BCB12_UP}
  {$DEFINE BCB11_UP}
  {$DEFINE BCB10_UP}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB12}
  {$DEFINE BCB12_UP}
  {$DEFINE BCB11_UP}
  {$DEFINE BCB10_UP}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB11}
  {$DEFINE BCB11_UP}
  {$DEFINE BCB10_UP}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB10}
  {$DEFINE BCB10_UP}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB9}
  {$DEFINE BCB9_UP}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB8}
  {$DEFINE BCB8_UP}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB7}
  {$DEFINE BCB7_UP}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB6}
  {$DEFINE BCB6_UP}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB5}
  {$DEFINE BCB5_UP}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB4}
  {$DEFINE BCB4_UP}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB3}
  {$DEFINE BCB3_UP}
  {$DEFINE BCB1_UP}
{$ENDIF}

{$IFDEF BCB1}
  {$DEFINE BCB1_UP}
{$ENDIF}

//------------------------------------------------------------------------------
// COMPILERX_UP from COMPILERX mappings
//------------------------------------------------------------------------------

{$IFDEF COMPILER26}
  {$DEFINE COMPILER26_UP}
  {$DEFINE COMPILER25_UP}
  {$DEFINE COMPILER24_UP}
  {$DEFINE COMPILER23_UP}
  {$DEFINE COMPILER22_UP}
  {$DEFINE COMPILER21_UP}
  {$DEFINE COMPILER20_UP}
  {$DEFINE COMPILER19_UP}
  {$DEFINE COMPILER18_UP}
  {$DEFINE COMPILER17_UP}
  {$DEFINE COMPILER16_UP}
  {$DEFINE COMPILER15_UP}
  {$DEFINE COMPILER14_UP}
  {$DEFINE COMPILER13_UP}
  {$DEFINE COMPILER11_UP}
  {$DEFINE COMPILER10_UP}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER25}
  {$DEFINE COMPILER25_UP}
  {$DEFINE COMPILER24_UP}
  {$DEFINE COMPILER23_UP}
  {$DEFINE COMPILER22_UP}
  {$DEFINE COMPILER21_UP}
  {$DEFINE COMPILER20_UP}
  {$DEFINE COMPILER19_UP}
  {$DEFINE COMPILER18_UP}
  {$DEFINE COMPILER17_UP}
  {$DEFINE COMPILER16_UP}
  {$DEFINE COMPILER15_UP}
  {$DEFINE COMPILER14_UP}
  {$DEFINE COMPILER13_UP}
  {$DEFINE COMPILER11_UP}
  {$DEFINE COMPILER10_UP}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER24}
  {$DEFINE COMPILER24_UP}
  {$DEFINE COMPILER23_UP}
  {$DEFINE COMPILER22_UP}
  {$DEFINE COMPILER21_UP}
  {$DEFINE COMPILER20_UP}
  {$DEFINE COMPILER19_UP}
  {$DEFINE COMPILER18_UP}
  {$DEFINE COMPILER17_UP}
  {$DEFINE COMPILER16_UP}
  {$DEFINE COMPILER15_UP}
  {$DEFINE COMPILER14_UP}
  {$DEFINE COMPILER13_UP}
  {$DEFINE COMPILER11_UP}
  {$DEFINE COMPILER10_UP}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER23}
  {$DEFINE COMPILER23_UP}
  {$DEFINE COMPILER22_UP}
  {$DEFINE COMPILER21_UP}
  {$DEFINE COMPILER20_UP}
  {$DEFINE COMPILER19_UP}
  {$DEFINE COMPILER18_UP}
  {$DEFINE COMPILER17_UP}
  {$DEFINE COMPILER16_UP}
  {$DEFINE COMPILER15_UP}
  {$DEFINE COMPILER14_UP}
  {$DEFINE COMPILER13_UP}
  {$DEFINE COMPILER11_UP}
  {$DEFINE COMPILER10_UP}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER22}
  {$DEFINE COMPILER22_UP}
  {$DEFINE COMPILER21_UP}
  {$DEFINE COMPILER20_UP}
  {$DEFINE COMPILER19_UP}
  {$DEFINE COMPILER18_UP}
  {$DEFINE COMPILER17_UP}
  {$DEFINE COMPILER16_UP}
  {$DEFINE COMPILER15_UP}
  {$DEFINE COMPILER14_UP}
  {$DEFINE COMPILER13_UP}
  {$DEFINE COMPILER11_UP}
  {$DEFINE COMPILER10_UP}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER21}
  {$DEFINE COMPILER21_UP}
  {$DEFINE COMPILER20_UP}
  {$DEFINE COMPILER19_UP}
  {$DEFINE COMPILER18_UP}
  {$DEFINE COMPILER17_UP}
  {$DEFINE COMPILER16_UP}
  {$DEFINE COMPILER15_UP}
  {$DEFINE COMPILER14_UP}
  {$DEFINE COMPILER13_UP}
  {$DEFINE COMPILER11_UP}
  {$DEFINE COMPILER10_UP}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER20}
  {$DEFINE COMPILER20_UP}
  {$DEFINE COMPILER19_UP}
  {$DEFINE COMPILER18_UP}
  {$DEFINE COMPILER17_UP}
  {$DEFINE COMPILER16_UP}
  {$DEFINE COMPILER15_UP}
  {$DEFINE COMPILER14_UP}
  {$DEFINE COMPILER13_UP}
  {$DEFINE COMPILER11_UP}
  {$DEFINE COMPILER10_UP}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER19}
  {$DEFINE COMPILER19_UP}
  {$DEFINE COMPILER18_UP}
  {$DEFINE COMPILER17_UP}
  {$DEFINE COMPILER16_UP}
  {$DEFINE COMPILER15_UP}
  {$DEFINE COMPILER14_UP}
  {$DEFINE COMPILER13_UP}
  {$DEFINE COMPILER11_UP}
  {$DEFINE COMPILER10_UP}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER18}
  {$DEFINE COMPILER18_UP}
  {$DEFINE COMPILER17_UP}
  {$DEFINE COMPILER16_UP}
  {$DEFINE COMPILER15_UP}
  {$DEFINE COMPILER14_UP}
  {$DEFINE COMPILER13_UP}
  {$DEFINE COMPILER11_UP}
  {$DEFINE COMPILER10_UP}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER17}
  {$DEFINE COMPILER17_UP}
  {$DEFINE COMPILER16_UP}
  {$DEFINE COMPILER15_UP}
  {$DEFINE COMPILER14_UP}
  {$DEFINE COMPILER13_UP}
  {$DEFINE COMPILER11_UP}
  {$DEFINE COMPILER10_UP}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER16}
  {$DEFINE COMPILER16_UP}
  {$DEFINE COMPILER15_UP}
  {$DEFINE COMPILER14_UP}
  {$DEFINE COMPILER13_UP}
  {$DEFINE COMPILER11_UP}
  {$DEFINE COMPILER10_UP}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER15}
  {$DEFINE COMPILER15_UP}
  {$DEFINE COMPILER14_UP}
  {$DEFINE COMPILER13_UP}
  {$DEFINE COMPILER11_UP}
  {$DEFINE COMPILER10_UP}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER14}
  {$DEFINE COMPILER14_UP}
  {$DEFINE COMPILER13_UP}
  {$DEFINE COMPILER11_UP}
  {$DEFINE COMPILER10_UP}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER13}
  {$DEFINE COMPILER13_UP}
  {$DEFINE COMPILER11_UP}
  {$DEFINE COMPILER10_UP}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER12}
  {$DEFINE COMPILER12_UP}
  {$DEFINE COMPILER11_UP}
  {$DEFINE COMPILER10_UP}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER11}
  {$DEFINE COMPILER11_UP}
  {$DEFINE COMPILER10_UP}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER10}
  {$DEFINE COMPILER10_UP}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER9}
  {$DEFINE COMPILER9_UP}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER8}
  {$DEFINE COMPILER8_UP}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER7}
  {$DEFINE COMPILER7_UP}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER6}
  {$DEFINE COMPILER6_UP}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER5}
  {$DEFINE COMPILER5_UP}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER4}
  {$DEFINE COMPILER4_UP}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER35}
  {$DEFINE COMPILER35_UP}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER3}
  {$DEFINE COMPILER3_UP}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER2}
  {$DEFINE COMPILER2_UP}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

{$IFDEF COMPILER1}
  {$DEFINE COMPILER1_UP}
{$ENDIF}

//------------------------------------------------------------------------------
// Map COMPILERX_UP to friendly feature names
//------------------------------------------------------------------------------

{$IFDEF COMPILER3_UP}
  {$DEFINE SUPPORTS_WIDESTRING}
  {$DEFINE SUPPORTS_INTERFACE}
{$ENDIF}

{$IFDEF COMPILER35_UP}
  {$DEFINE SUPPORTS_EXTSYM}
  {$DEFINE SUPPORTS_NODEFINE}
{$ENDIF}

{$IFDEF COMPILER4_UP}
  {$DEFINE SUPPORTS_INT64}
  {$DEFINE SUPPORTS_DYNAMICARRAYS}
  {$DEFINE SUPPORTS_DEFAULTPARAMS}
  {$DEFINE SUPPORTS_OVERLOAD}
{$ENDIF}

//------------------------------------------------------------------------------
// Cross-platform related defines
//------------------------------------------------------------------------------

{$IFDEF WIN32}
  {$DEFINE MSWINDOWS}
{$ENDIF}

{$IFDEF LINUX}
  {$DEFINE UNIX}
  {$DEFINE COMPLIB_CLX}
{$ENDIF}

{$IFNDEF COMPLIB_CLX}
  {$DEFINE COMPLIB_VCL}
{$ENDIF}

