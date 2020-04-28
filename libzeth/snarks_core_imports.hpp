// Copyright (c) 2015-2020 Clearmatics Technologies Ltd
//
// SPDX-License-Identifier: LGPL-3.0+

#ifndef __ZETH_SNARKS_CORE_IMPORTS_HPP__
#define __ZETH_SNARKS_CORE_IMPORTS_HPP__

#ifdef ZKSNARK_PGHR13
#include "libzeth/snarks/pghr13/core.hpp"
#elif ZKSNARK_GROTH16
#include "libzeth/snarks/groth16/core.hpp"
#else
#error You must define one of the SNARK_* symbols indicated into the
CMakelists.txt file.#endif
#endif

#endif // __ZETH_SNARKS_CORE_IMPORTS_HPP__
