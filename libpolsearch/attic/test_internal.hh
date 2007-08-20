/**
 * @file
 *
 * Internal routines related to logic tests.
 *
 * @author Jeremy A. Mowery jmowery@tresys.com
 * @author Jason Tang  jtang@tresys.com
 *
 * Copyright (C) 2007 Tresys Technology, LLC
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef POLSEARCH_TEST_INTERNAL_H
#define POLSEARCH_TEST_INTERNAL_H

#include <polsearch/test.hh>

#ifdef __cplusplus
extern "C"
{
#endif

	/**
	 * Free callback for polsearch_test objects in apol vectors.
	 * @param pt Pointer to a polsearch_test object to destroy.
	 */
	void free_test(void *pt);

	/**
	 * Duplicate callback for polsearch_test objects in apol vectors.
	 * @param pt Pointer to a polsearch_test object to copy.
	 * @param x Unused parameter
	 */
	void *dup_test(const void *pt, void *x __attribute__ ((unused)));

	/**
	 * Free callback for polsearch_result objects in apol vectors.
	 * @param pr Pointer to a polsearch_result object to destroy.
	 */
	void free_result(void *pr);

	/**
	 * Duplicate callback for polsearch_result objects in apol vectors.
	 * @param pr Pointer to a polsearch_result object to copy.
	 * @param x Unused parameter
	 */
	void *dup_result(const void *pr, void *x __attribute__ ((unused)));

	/**
	 * Comparison callback for polsearch_result objects in apol vectors
	 * suitable for passing to sort.
	 * @param a A result entry.
	 * @param b A result entry.
	 * @param data Policy from which to get symbol names.
	 * @return Less than, equal to, or grater than 0 if \a a should appear
	 * before \a b, be merged with \a b, or appear after \a b in the results.
	 */
	int result_cmp(const void *a, const void *b, void *data);

	/**
	 * Merge the results from a single test into the master list of results.
	 * Result and proof entries will be duplicated or destroyed as needed such
	 * that it is safe to call apol_vector_destroy() on \a cur_results after
	 * calling this function.
	 * @param policy The policy from which the elements in the results come.
	 * @param master_results The master list of results from all tests run.
	 * @param cur_results The list of results from the most recent test run.
	 * @param m The matching method used for multiple tests.
	 * If POLSEARCH_MATCH_ALL, entries must appear in both vectors to be reported;
	 * if POLSEARCH_MATCH_ANY, new entries from \a cur_results will be added to
	 * \a master_results.
	 * @exception std::bad_alloc Could not allocate space to duplicate entries.
	 */
	void merge_results(const apol_policy_t * policy, apol_vector_t * master_results,
			   apol_vector_t * cur_results, polsearch_match_e m) throw(std::bad_alloc);

	/**
	 * Free callback for polsearch_proof objects in apol vectors.
	 * @param pp Pointer to a polsearch_proof object to destroy.
	 */
	void free_proof(void *pp);

	/**
	 * Duplicate callback for polsearch_proof objects in apol vectors.
	 * @param pp Pointer to a polsearch_proof object to copy.
	 * @param x Unused parameter.
	 */
	void *dup_proof(const void *pp, void *x __attribute__ ((unused)));

	/**
	 * Comparison callback for polsearch_proof objects in apol vectors
	 * suitable for passing to sort.
	 * @param a A proof entry.
	 * @param b A proof entry.
	 * @param data Policy from which to get symbol names.
	 * @return Less than, equal to, or grater than 0 if \a a should appear
	 * before \a b, be merged with \a b, or appear after \a b in the results.
	 */
	int proof_cmp(const void *a, const void *b, void *data);

	/**
	 * Merge the proof from a single result into the master list of proof.
	 * Proof entries will be duplicated as needed such that it is
	 * save to call apol_vector_destroy() on \a cur_proof after calling this
	 * function.
	 * @param policy The policy from which the elements in the results come.
	 * @param master_proof The master list of proof from all tests run.
	 * @param cur_proof The list of proof from the most recent test run.
	 * @exception std::bad_alloc Could not allocate space to duplicate entries.
	 */
	void merge_proof(const apol_policy_t * policy, apol_vector_t * master_proof,
			 apol_vector_t * cur_proof) throw(std::bad_alloc);

#ifdef __cplusplus
}
#endif

#endif				       /* POLSEARCH_TEST_INTERNAL_H */