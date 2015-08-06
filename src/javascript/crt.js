/* crt.js
 * Javascript C runtime.
 *
 * © 2008 David Given.
 * Clue is licensed under the Revised BSD open source license. To get the
 * full license text, see the README file.
 *
 * $Id: crt.js 46 2008-09-07 12:23:03Z dtrg $
 * $HeadURL: https://cluecc.svn.sourceforge.net/svnroot/cluecc/clue/src/javascript/crt.js $
 * $LastChangedDate: 2007-04-30 22:41:42 +0000 (Mon, 30 Apr 2007) $
 */

var clue_initializer_list = [];

function clue_add_initializer(i)
{
	clue_initializer_list.push(i);
}

function clue_run_initializers()
{
	while (clue_initializer_list.length > 0)
		clue_initializer_list.shift()();
}

function clue_ptrtostring(po, pd)
{
	var s = [];
	for (;;)
	{
		var c = pd[po];
		if (c == 0)
			break;
		else
			s.push(c);
		po++;
	}
	
	return String.fromCharCode.apply(null, s);
}

function clue_newstring(s)
{
	var d = [];
	
	for (var i = 0; i < s.length; i++)
		d[i] = s.charCodeAt(i);
	d[s.length] = 0;
	
	return d;
}
