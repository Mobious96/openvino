// Copyright (C) 2018-2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <memory>
#include <utility>

#include <transformations_visibility.hpp>
#include <ngraph/pass/graph_rewrite.hpp>

namespace ngraph {
namespace pass {

class TRANSFORMATIONS_API LinOpSequenceFusion;
class TRANSFORMATIONS_API AddMultiplyFusion;
class TRANSFORMATIONS_API AddAddFusion;
class TRANSFORMATIONS_API MultiplyMultiplyFusion;

}  // namespace pass
}  // namespace ngraph

class ngraph::pass::LinOpSequenceFusion: public ngraph::pass::GraphRewrite {
public:
    LinOpSequenceFusion() {
        add_matcher<ngraph::pass::AddMultiplyFusion>();
        add_matcher<ngraph::pass::AddAddFusion>();
        add_matcher<ngraph::pass::MultiplyMultiplyFusion>();
    }
};

class ngraph::pass::AddMultiplyFusion: public ngraph::pass::MatcherPass {
public:
    AddMultiplyFusion();
};

class ngraph::pass::AddAddFusion: public ngraph::pass::MatcherPass {
public:
    AddAddFusion();
};

class ngraph::pass::MultiplyMultiplyFusion: public ngraph::pass::MatcherPass {
public:
    MultiplyMultiplyFusion();
};
