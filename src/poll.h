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

#pragma once

typedef void (*poll_cb)(int fd);

/**
 * Initialize polling
 */
void poll_init(void);

/**
 * Add a callback
 */
void poll_mod(int fd, poll_cb cb, gboolean read, gboolean write);

/**
 * Remove an FD
 */
void poll_rm(int fd);

/**
 * Run the main loop
 */
void poll_run(void);
