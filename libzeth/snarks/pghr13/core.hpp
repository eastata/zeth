// Copyright (c) 2015-2020 Clearmatics Technologies Ltd
//
// SPDX-License-Identifier: LGPL-3.0+

#ifndef __ZETH_SNARKS_PGHR13_CORE_HPP__
#define __ZETH_SNARKS_PGHR13_CORE_HPP__

#include <boost/filesystem.hpp>
#include <libsnark/gadgetlib1/protoboard.hpp>
#include <libsnark/zk_proof_systems/ppzksnark/r1cs_ppzksnark/r1cs_ppzksnark.hpp>

namespace libzeth
{

template<typename ppT> class pghr13snark
{
public:
    typedef libsnark::r1cs_ppzksnark_proving_key<ppT> ProvingKeyT;
    typedef libsnark::r1cs_ppzksnark_verification_key<ppT> VerifKeyT;
    typedef libsnark::r1cs_ppzksnark_keypair<ppT> KeypairT;
    typedef libsnark::r1cs_ppzksnark_proof<ppT> ProofT;

    static KeypairT generate_setup(
        const libsnark::protoboard<libff::Fr<ppT>> &pb);

    static ProofT generate_proof(
        const libsnark::protoboard<libff::Fr<ppT>> &pb,
        const ProvingKeyT &proving_key);

    static bool verify(
        const libsnark::r1cs_primary_input<libff::Fr<ppT>> &primary_inputs,
        const ProofT &proof,
        const VerifKeyT &verification_key);

    static void export_verification_key(const KeypairT &keypair);

    static void display_proof(const ProofT &proof);

    static void verification_key_to_json(
        const VerifKeyT &keypair, boost::filesystem::path path = "");

    static void proof_and_inputs_to_json(
        const ProofT &proof,
        const libsnark::r1cs_primary_input<libff::Fr<ppT>> &input,
        boost::filesystem::path path = "");

    static void proof_to_json(
        const ProofT &proof, boost::filesystem::path path);

    /// Write a keypair to a stream.
    static void write_keypair(std::ostream &out, const KeypairT &keypair);

    /// Read a keypair from a stream.
    static KeypairT read_keypair(std::istream &in);
};

} // namespace libzeth

#include "libzeth/snarks/pghr13/core.tcc"

#endif // __ZETH_SNARKS_PGHR13_CORE_HPP__
