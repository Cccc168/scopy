/*
 * This file is part of the PulseView project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
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
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#include "property.hpp"

namespace pv {
namespace prop {

Property::Property(QString name, Getter getter, Setter setter) :
	getter_(getter),
	setter_(setter),
	name_(name)
{
}

const QString& Property::name() const
{
	return name_;
}

bool Property::labeled_widget() const
{
	return false;
}

Glib::VariantBase Property::get()
{
	return getter_();
}


void Property::set(Glib::VariantBase val)
{
	return setter_(val);
}

} // prop
} // pv
