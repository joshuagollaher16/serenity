/*
 * Copyright (c) 2022, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/CSS/Length.h>
#include <LibWeb/CSS/Percentage.h>

namespace Web::CSS {

class Size {
public:
    enum class Type {
        Auto,
        Length,
        Percentage,
        MinContent,
        MaxContent,
        FitContent,
        None, // NOTE: This is only valid for max-width and max-height.
    };

    static Size make_auto();
    static Size make_length(Length);
    static Size make_percentage(Percentage);
    static Size make_min_content();
    static Size make_max_content();
    static Size make_fit_content(Length available_space);
    static Size make_none();

    bool is_auto() const { return m_type == Type::Auto; }
    bool is_length() const { return m_type == Type::Length; }
    bool is_percentage() const { return m_type == Type::Percentage; }
    bool is_min_content() const { return m_type == Type::MinContent; }
    bool is_max_content() const { return m_type == Type::MaxContent; }
    bool is_fit_content() const { return m_type == Type::FitContent; }
    bool is_none() const { return m_type == Type::None; }

    // FIXME: This is a stopgap API that will go away once all layout code is aware of CSS::Size.
    CSS::Length resolved(Layout::Node const&, Length const& reference_value) const;

    bool contains_percentage() const;

    CSS::Length const& length() const
    {
        VERIFY(is_length());
        return m_length_percentage.length();
    }

    CSS::Percentage const& percentage() const
    {
        VERIFY(is_percentage());
        return m_length_percentage.percentage();
    }

    CSS::Length const& fit_content_available_space() const
    {
        VERIFY(is_fit_content());
        return m_length_percentage.length();
    }

private:
    Size(Type type, LengthPercentage);

    Type m_type {};
    CSS::LengthPercentage m_length_percentage;
};

}
