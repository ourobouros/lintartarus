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

#include <glib.h>
#include <stdlib.h>
#include "const.h"
#include "udev.h"

#define UDEV_FILE \
	"# Generated by lintartarus\n" \
	"SUBSYSTEMS==\"usb\", " \
		"ATTRS{idVendor}==\"" G_STRINGIFY(VENDOR_NO_X) "\", " \
		"ATTRS{idProduct}==\"" G_STRINGIFY(PRODUCT_NO_X) "\", " \
		"GROUP=\"%s\", MODE=\"0660\"\n" \
	"KERNEL==\"uinput\", MODE=\"660\", GROUP=\"%s\"\n" \
	"SUBSYSTEM==\"input\", " \
		"ENV{ID_BUS}==\"usb\", " \
		"ENV{ID_VENDOR_ID}==\"" G_STRINGIFY(VENDOR_NO_X) "\", " \
		"ENV{ID_MODEL_ID}==\"" G_STRINGIFY(PRODUCT_NO_X) "\", " \
		"ENV{ID_INPUT_KEYBOARD}==\"1\", " \
		"GROUP=\"%s\", MODE=\"0660\"\n"

void udev_authorize(const char *group)
{
	GError *error = NULL;
	GString *buff = g_string_new("");

	if (group == NULL) {
		group = "plugdev";
	}

	g_string_printf(buff, UDEV_FILE, group, group, group);
	g_file_set_contents(
		"/etc/udev/rules.d/99-lintartarus.rules",
		buff->str,
		buff->len,
		&error);
	if (error != NULL) {
		g_error("failed to create rules file: %s", error->message);
	}

	g_string_free(buff, TRUE);
	exit(0);
}
