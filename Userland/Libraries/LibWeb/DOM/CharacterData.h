/*
 * Copyright (c) 2018-2020, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/String.h>
#include <LibWeb/DOM/ChildNode.h>
#include <LibWeb/DOM/Node.h>
#include <LibWeb/DOM/NonDocumentTypeChildNode.h>

namespace Web::DOM {

class CharacterData
    : public Node
    , public ChildNode<CharacterData>
    , public NonDocumentTypeChildNode<CharacterData> {
    WEB_PLATFORM_OBJECT(CharacterData, Node);

public:
    virtual ~CharacterData() override = default;

    String const& data() const { return m_data; }
    void set_data(String);

    unsigned length() const { return m_data.length(); }

    WebIDL::ExceptionOr<String> substring_data(size_t offset, size_t count) const;
    WebIDL::ExceptionOr<void> append_data(String const&);
    WebIDL::ExceptionOr<void> insert_data(size_t offset, String const&);
    WebIDL::ExceptionOr<void> delete_data(size_t offset, size_t count);
    WebIDL::ExceptionOr<void> replace_data(size_t offset, size_t count, String const&);

protected:
    explicit CharacterData(Document&, NodeType, String const&);

private:
    String m_data;
};

}
