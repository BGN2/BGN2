#include "circuit_multiplicationL2.hpp"
void circuit_multiplicationL2(PublicKey public_key, PrivateKey private_key)
{
	F2 zero=0, un=0, produit=0;
	BitEvalL1<curvepoint_fp_t> bit_chiffre_0_curve, bit_chiffre_1_curve;
	BitEvalL1<twistpoint_fp2_t> bit_chiffre_0_twist, bit_chiffre_1_twist;
	BitEvalL2 chiffre_L2_0, chiffre_L2_1;
	BitEvalL4 chiffre_produit;
	
	chiffrement(bit_chiffre_0_curve,0,public_key);
	chiffrement(bit_chiffre_1_curve,1,public_key);
	chiffrement(bit_chiffre_0_twist,0,public_key);
	chiffrement(bit_chiffre_1_twist,1,public_key);
	chiffre_L2_0 = multiplicationL1(bit_chiffre_0_curve,bit_chiffre_0_twist,public_key);
	chiffre_L2_1 = multiplicationL1(bit_chiffre_1_curve,bit_chiffre_1_twist,public_key);	
	dechiffrementL2(zero,chiffre_L2_0,private_key);	
	dechiffrementL2(un,chiffre_L2_1,private_key);	
	zout(zero,un);
	
	
	cout << "cas #1 0*0" << endl;
	
	chiffre_produit=multiplicationL2(chiffre_L2_0,chiffre_L2_0,public_key);
	dechiffrementL4(produit,chiffre_produit,private_key);
	zout(produit);
	
	//exit(0);
		
	cout << "cas #2 0*1" << endl;

	chiffre_produit=multiplicationL2(chiffre_L2_0,chiffre_L2_1,public_key);
	dechiffrementL4(produit,chiffre_produit,private_key);
	zout(produit);
		
	cout << "cas #3 1*0" << endl;

	chiffre_produit=multiplicationL2(chiffre_L2_1,chiffre_L2_0,public_key);
	dechiffrementL4(produit,chiffre_produit,private_key);
	zout(produit);
		
	cout << "cas #4 1*1" << endl;
	
	chiffre_produit=multiplicationL2(chiffre_L2_1,chiffre_L2_1,public_key);
	dechiffrementL4(produit,chiffre_produit,private_key);
	zout(produit);
	
	JUMP;
	cout << "taille d'un chiffré de niveau 4 = " << sizeof(chiffre_produit)+sizeof(Quadripoint)*(chiffre_produit.get_vec_quadripoints(0).capacity()+ chiffre_produit.get_vec_quadripoints(1).capacity()) << " octets" << endl;
			
}
