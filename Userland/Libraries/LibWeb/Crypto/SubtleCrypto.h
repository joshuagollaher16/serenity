/*
 * Copyright (c) 2021-2022, Linus Groh <linusg@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Forward.h>
#include <LibWeb/Bindings/PlatformObject.h>

namespace Web::Crypto {

class SubtleCrypto final : public Bindings::PlatformObject {
    WEB_PLATFORM_OBJECT(SubtleCrypto, Bindings::PlatformObject);

public:
    static JS::NonnullGCPtr<SubtleCrypto> create(HTML::Window&);

    virtual ~SubtleCrypto() override;

    JS::Promise* digest(String const& algorithm, JS::Handle<JS::Object> const& data);

private:
    explicit SubtleCrypto(HTML::Window&);
};

}
