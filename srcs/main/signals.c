/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:52:51 by fgastal-          #+#    #+#             */
/*   Updated: 2022/12/20 12:59:08 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	void rl_replace_line (const char *text, int clear_undo)
	Replace the contents of rl_line_buffer with text. 
	The point and mark are preserved, if possible. 
	If clear_undo is non-zero, the undo list associated 
	with the current line is cleared.
*/

/*
	void rl_redisplay (void)
	Change what’s displayed on the screen to reflect 
	the current contents of rl_line_buffer.
*/
static void	handle_sigint_fork(int signal)
{
	(void) signal;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_redisplay();
}

/*
	int rl_on_new_line ()
	Tell the update routines that we have moved onto 
	a new (empty) line, usually after ouputting a newline.
*/
static void	handle_sigint(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

/*
	SIGINT - Interrupt from keyboard;

	SIGQUIT - Quit from keyboard;

	SIG_IGN specifies that the signal should be ignored.
	Your program generally should not ignore signals that 
	represent serious events or that are normally used to 
	request termination. You cannot ignore the SIGKILL or 
	SIGSTOP signals at all. You can ignore program error 
	signals like SIGSEGV, but ignoring the error won’t enable 
	the program to continue executing meaningfully. Ignoring 
	user requests such as SIGINT, SIGQUIT, and SIGTSTP is unfriendly.

	When you do not wish signals to be delivered during a certain
	part of the program, the thing to do is to block them, 
	not ignore them.
*/
void	handle_signal(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	handle_signal_fork(void)
{
	signal(SIGINT, handle_sigint_fork);
	signal(SIGQUIT, SIG_IGN);
}
