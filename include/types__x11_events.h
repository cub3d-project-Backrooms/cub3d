/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__x11_events.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES__X11_EVENTS_H
# define TYPES__X11_EVENTS_H

typedef enum e_x11events
{
	X11EVENTS__KeyPress = 2,
	X11EVENTS__KeyRelease,
	X11EVENTS__ButtonPress,
	X11EVENTS__ButtonRelease,
	X11EVENTS__MotionNotify,
	X11EVENTS__EnterNotify,
	X11EVENTS__LeaveNotify,
	X11EVENTS__FocusIn,
	X11EVENTS__FocusOut,
	X11EVENTS__KeymapNotify,
	X11EVENTS__Expose,
	X11EVENTS__GraphicsExpose,
	X11EVENTS__NoExpose,
	X11EVENTS__VisibilityNotify,
	X11EVENTS__CreateNotify,
	X11EVENTS__DestroyNotify,
	X11EVENTS__UnmapNotify,
	X11EVENTS__MapNotify,
	X11EVENTS__MapRequest,
	X11EVENTS__ReparentNotify,
	X11EVENTS__ConfigureNotify,
	X11EVENTS__ConfigureRequest,
	X11EVENTS__GravityNotify,
	X11EVENTS__ResizeRequest,
	X11EVENTS__CirculateNotify,
	X11EVENTS__CirculateRequest,
	X11EVENTS__PropertyNotify,
	X11EVENTS__SelectionClear,
	X11EVENTS__SelectionRequest,
	X11EVENTS__SelectionNotify,
	X11EVENTS__ColormapNotify,
	X11EVENTS__ClientMessage,
	X11EVENTS__MappingNotify,
	X11EVENTS__GenericEvent,
	X11EVENTS__LASTEvent,
}	t_x11events;

typedef enum e_x11masks
{
	X11MASKS__NoEventMask = 0L,
	X11MASKS__KeyPressMask = (1L << 0),
	X11MASKS__KeyReleaseMask = (1L << 1),
	X11MASKS__ButtonPressMask = (1L << 2),
	X11MASKS__ButtonReleaseMask = (1L << 3),
	X11MASKS__EnterWindowMask = (1L << 4),
	X11MASKS__LeaveWindowMask = (1L << 5),
	X11MASKS__PointerMotionMask = (1L << 6),
	X11MASKS__PointerMotionHintMask = (1L << 7),
	X11MASKS__Button1MotionMask = (1L << 8),
	X11MASKS__Button2MotionMask = (1L << 9),
	X11MASKS__Button3MotionMask = (1L << 10),
	X11MASKS__Button4MotionMask = (1L << 11),
	X11MASKS__Button5MotionMask = (1L << 12),
	X11MASKS__ButtonMotionMask = (1L << 13),
	X11MASKS__KeymapStateMask = (1L << 14),
	X11MASKS__ExposureMask = (1L << 15),
	X11MASKS__VisibilityChangeMask = (1L << 16),
	X11MASKS__StructureNotifyMask = (1L << 17),
	X11MASKS__ResizeRedirectMask = (1L << 18),
	X11MASKS__SubstructureNotifyMask = (1L << 19),
	X11MASKS__SubstructureRedirectMask = (1L << 20),
	X11MASKS__FocusChangeMask = (1L << 21),
	X11MASKS__PropertyChangeMask = (1L << 22),
	X11MASKS__ColormapChangeMask = (1L << 23),
	X11MASKS__OwnerGrabButtonMask = (1L << 24)
}	t_x11masks;

#endif
