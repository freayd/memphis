/*
 * Memphis - Cairo Rederer for OSM in C
 * Copyright (C) 2008  Marius Rieder <marius.rieder@durchmesser.ch>
 * Copyright (C) 2009  Simon Wenner <simon@wenner.ch>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef OSM05_H
#define OSM05_H

#include <glib.h>

typedef struct osmTag_ osmTag;
struct osmTag_ {
        char *key;
        char *value;
        osmTag *next;
    };

typedef struct osmNode_ osmNode;
struct osmNode_ {
        int id;
        float lat;
        float lon;
        short int layer;
        osmTag *tag; // FIXME: this is a list! -> tags
        osmNode *next;
    };

typedef struct osmWay_ osmWay;
struct osmWay_ {
        int id;
        short int layer;
        char    *name;
        osmTag  *tag; // FIXME: this is a list! -> tags
        GSList  *nd;
        osmWay  *next;
    };

typedef struct osmMember_ osmMember;
struct osmMember_ {
        osmNode     *node;
        osmWay      *way;
        char        *role;
        osmMember   *next;
    };

typedef struct osmRelation_ omsRelation;
struct osmRelation_ {
        int         id;
        osmTag      *tag;
        osmMember   *member;
    };

typedef struct osmFile_ osmFile;
struct osmFile_ {
        osmNode         *nodes;     // Node List
        GHashTable      *nodeidx;   // Node Hash
        guint           nodecnt;    // Node Count
        osmWay          *ways;
        guint           waycnt;
        gfloat          minlat;
        gfloat          minlon;
        gfloat          maxlat;
        gfloat          maxlon;
    };

osmFile* osmRead (const char *filename, GError **error);
osmFile* osmRead_from_buffer (const char *buffer, guint size, GError **error);
void osmFree(osmFile *osm);

#endif /* OSM05_H */

/*
 * vim: expandtab shiftwidth=4 tabstop=4:
 */

