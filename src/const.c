/*
 * lintartarus: key mapping and light control for the Razer Tartarus on Linux
 * Copyright (C) 2015 Andrew Stone <a@stoney.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "const.h"

const char *light_level_cmd =
	"\x00\xff\x00\x00\x00\x03\x03\x03\x01\x05\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";

const char *pulsate_cmd =
	"\x00\xff\x00\x00\x00\x03\x03\x02\x01\x05\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";

const char *layout_cmds[] = {
	"\x00\xff\x00\x00\x00\x03\x03\x00\x01\x0c\x00\x00\x00\x00\x00\x00\x00\x00"
		"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
		"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
		"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
		"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
	"\x00\xff\x00\x00\x00\x03\x03\x00\x01\x0d\x00\x00\x00\x00\x00\x00\x00\x00"
		"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
		"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
		"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
		"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
	"\x00\xff\x00\x00\x00\x03\x03\x00\x01\x0e\x00\x00\x00\x00\x00\x00\x00\x00"
		"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
		"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
		"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
		"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
};

const struct light_val light_levels[] = {
	// off
	{	.a = 0x00,
		.b = 0x07
	},

	// low
	{	.a = 0x49,
		.b = 0x4e
	},

	// medium
	{	.a = 0xa3,
		.b = 0xa4
	},

	// high
	{	.a = 0xff,
		.b = 0xf8
	},
};

const struct light_val pulsate_vals[] = {
	// solid / off
	{	.a = 0x00,
		.b = 0x06
	},

	// pulsate / on
	{	.a = 0x02,
		.b = 0x04
	},
};

const struct layout_val layout_vals[] = {
	// Unlike windows, layout 0 is all lights off
	{	.a = {
			.a = 0x00,
			.b = 0x0d
		},
		.b = {
			.a = 0x00,
			.b = 0x0c,
		},
		.c = {
			.a = 0x00,
			.b = 0x0f
		},
	},

	{	.a = {
			.a = 0x00,
			.b = 0x0d
		},
		.b = {
			.a = 0x00,
			.b = 0x0c,
		},
		.c = {
			.a = 0x01,
			.b = 0x0e
		},
	},
	{	.a = {
			.a = 0x01,
			.b = 0x0c
		},
		.b = {
			.a = 0x00,
			.b = 0x0c,
		},
		.c = {
			.a = 0x00,
			.b = 0x0f
		},
	},
	{	.a = {
			.a = 0x00,
			.b = 0x0d
		},
		.b = {
			.a = 0x01,
			.b = 0x0d,
		},
		.c = {
			.a = 0x00,
			.b = 0x0f
		},
	},
	{	.a = {
			.a = 0x01,
			.b = 0x0c
		},
		.b = {
			.a = 0x00,
			.b = 0x0c,
		},
		.c = {
			.a = 0x01,
			.b = 0x0e
		},
	},
	{	.a = {
			.a = 0x00,
			.b = 0x0d
		},
		.b = {
			.a = 0x01,
			.b = 0x0d,
		},
		.c = {
			.a = 0x01,
			.b = 0x0e
		},
	},
	{	.a = {
			.a = 0x01,
			.b = 0x0c
		},
		.b = {
			.a = 0x01,
			.b = 0x0d,
		},
		.c = {
			.a = 0x00,
			.b = 0x0f
		},
	},
	{	.a = {
			.a = 0x01,
			.b = 0x0c
		},
		.b = {
			.a = 0x01,
			.b = 0x0d,
		},
		.c = {
			.a = 0x01,
			.b = 0x0e
		},
	},
};
