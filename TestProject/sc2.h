/*
	Simple Console Interface Library v2
	
	by 0nepeop1e
*/
#ifndef SIMCON2
#define SIMCON2

#ifdef _DEBUG
#pragma comment(lib, "..\\SimCon2\\bin\\Debug\\sc2.lib")
#else
#pragma comment(lib, "..\\SimCon2\\bin\\Release\\sc2.lib")
#endif

/// <summary>
/// Set the code page using by SimCon2 and the console,
/// default code page using is system default.
/// </summary>
/// <returns>true if success, false if the code page not
/// supported or invalid.</returns>
/// <param name="CodePage">Code Page Identifier</param>
_Bool _cdecl sc2_encoding(int CodePage);

/// <summary>
/// Get string input
/// </summary>
/// <returns>true if not overflow.</returns>
/// <param name="output">where to store the data</param>
/// <param name="size">size of array</param>
_Bool _cdecl sc2_getstr(char * output, size_t size);

/// <summary>
/// Get password input
/// </summary>
/// <param name="output">where to store the data</param>
/// <param name="size">size of array</param>
/// <param name="mask">character for mask, can use a wide character</param>
void _cdecl sc2_getpwd(char* output, size_t size, wchar_t mask);

/// <summary>
/// Get wide string input
/// </summary>
/// <returns>true if not overflow.</returns>
/// <param name="output">where to store the data</param>
/// <param name="size">size of array</param>
_Bool _cdecl sc2_getwcs(wchar_t * output, size_t size);

/// <summary>
/// Read the console input and store it
/// </summary>
/// <returns>size of char array required to store the string
/// included null character.</returns>
size_t _cdecl sc2_store();

/// <summary>
/// Read the console input and store it
/// </summary>
/// <returns>size of wchar_t array required to store the
/// string included null character.</returns>
size_t _cdecl sc2_store_w();

/// <summary>
/// Retrieve stored string as multibyte to buffer
/// </summary>
/// <returns>true if not overflow.</returns>
/// <param name="buffer">where to store the data</param>
/// <param name="size">size of array</param>
_Bool _cdecl sc2_getstore(char * buffer, size_t size);

/// <summary>
/// Retrieve stored string as widechar to buffer
/// </summary>
/// <returns>true if not overflow.</returns>
/// <param name="buffer">where to store the data</param>
/// <param name="size">size of array</param>
_Bool _cdecl sc2_getstore_w(wchar_t * buffer, size_t size);

/// <summary>
/// Get integer input
/// </summary>
/// <returns>true if user input a valid value.</returns>
/// <param name="output">where to store the data</param>
_Bool _cdecl sc2_getint(int * output);

/// <summary>
/// Get float input
/// </summary>
/// <returns>true if user input a valid value.</returns>
/// <param name="output">where to store the data</param>
_Bool _cdecl sc2_getfloat(float * output);

/// <summary>
/// Confirm from user.
/// </summary>
/// <returns>true if yes</returns>
/// <param name="prompt">true to prompt the "(Y/N)?" and answer.</param>
_Bool _cdecl sc2_confirm(_Bool prompt);

/// <summary>
/// Set the console title
/// </summary>
/// <param name="title">New title for the console</param>
void _cdecl sc2_title(char * title);

/// <summary>
/// Clear the console screen
/// </summary>
void _cdecl sc2_clrscr();

/// <summary>
/// Pause the console
/// </summary>
void _cdecl sc2_pause();

/// <summary>
/// Beep sound!
/// </summary>
void _cdecl sc2_beep();

/// <summary>
/// Callback function for SimCon2 Menu
/// </summary>
/// <returns>result of callback</returns>
/// <param name="index">index of selected item</param>
typedef int (_cdecl *sc2m_callback)(int index);

/// <summary>
/// Set the callback function which will apply to the items
/// which doesn't have callback.
/// </summary>
/// <param="callback">the callback function</param>
void _cdecl sc2m_set_callback(sc2m_callback callback);

/// <summary>
/// Show menu with a specific title
/// </summary>
/// <param="title">the title</param>
int _cdecl sc2m_show(char * title);

/// <summary>
/// Show menu with a specific title
/// </summary>
/// <param="title">the title</param>
int _cdecl sc2m_show_w(wchar_t * title);

/// <summary>
/// Add an item into menu
/// </summary>
/// <param="name">Item name</param>
/// <param="tips">Tips for item, set null to disable</param>
/// <param="callback">Callback when item selected, nullable</param>
void _cdecl sc2m_add(char * name, char * tips, sc2m_callback callback);

/// <summary>
/// Add an item into menu
/// </summary>
/// <param="name">Item name</param>
/// <param="tips">Tips for item, set null to disable</param>
/// <param="callback">Callback when item selected, nullable</param>
void _cdecl sc2m_add_w(wchar_t * name, wchar_t * tips, sc2m_callback callback);

/// <summary>
/// Insert an item into menu with specific index
/// </summary>
/// <param="index">the index</param>
/// <param="name">Item name</param>
/// <param="tips">Tips for item, set null to disable</param>
/// <param="callback">Callback when item selected, nullable</param>
void _cdecl sc2m_insert(int index, char * name, char * tips, sc2m_callback callback);

/// <summary>
/// Insert an item into menu with specific index
/// </summary>
/// <param="index">the index</param>
/// <param="name">Item name</param>
/// <param="tips">Tips for item, set null to disable</param>
/// <param="callback">Callback when item selected, nullable</param>
void _cdecl sc2m_insert_w(int index, wchar_t * name, wchar_t * tips, sc2m_callback callback);

/// <summary>
/// remove an item in the menu which is located at the index.
/// </summary>
/// <param="index">the index</param>
void _cdecl sc2m_remove(int index);

/// <summary>
/// remove all items and clear the callback.
/// </summary>
void _cdecl sc2m_reset();

#endif