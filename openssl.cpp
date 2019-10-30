#include "stdafx.h"
#include "OpenSSL.h"

#pragma comment(lib, "libeay32.lib")


COpenSSL::COpenSSL()
{
}


COpenSSL::~COpenSSL()
{
}

void COpenSSL::openssl_des3(const unsigned char *input, unsigned int length_input, int type, int mode, unsigned char key[24], unsigned char ivec[8], unsigned char **output, unsigned int &length_output)
{
	size_t i, block;
	unsigned char buffer_in[8];
	unsigned char k1[8], k2[8], k3[8];
	
	DES_key_schedule ks1, ks2, ks3;

	memcpy_s(k1, sizeof(k1), key, sizeof(k1));
	memcpy_s(k2, sizeof(k1), key + 8, sizeof(k1));
	memcpy_s(k3, sizeof(k1), key + 16, sizeof(k1));

	DES_set_key_unchecked((const_DES_cblock*)k1, &ks1);
	DES_set_key_unchecked((const_DES_cblock*)k2, &ks2);
	DES_set_key_unchecked((const_DES_cblock*)k3, &ks3);

	length_output = ((length_input / 8) + (length_input % 8 ? 1 : 0)) * 8;

	*output = new unsigned char[length_output];
	memset(*output, 0, length_output);

	switch (mode)
	{
	case MODE_CBC:
		DES_ede3_cbc_encrypt((const unsigned char*)input, (unsigned char*)(*output), length_input, &ks1, &ks2, &ks3, (DES_cblock*)ivec, type);
			break;
	case MODE_CFB:
		DES_ede3_cfb_encrypt((const unsigned char*)input, (unsigned char*)(*output), 8, length_input, &ks1, &ks2, &ks3, (DES_cblock*)ivec, type);
		break;
	default:
		block = length_input / 8;
		for (i = 0; i < block; i++)
		{
			memcpy_s(buffer_in, sizeof(buffer_in), input + i * 8, sizeof(buffer_in));
			DES_ecb3_encrypt((const_DES_cblock*)buffer_in, (const_DES_cblock*)(*output + i * 8), &ks1, &ks2, &ks3, type);
		}

		if (length_input % 8)
		{
			memset(buffer_in, 0, sizeof(buffer_in));
			memcpy_s(buffer_in, sizeof(buffer_in), input + i * 8, sizeof(buffer_in));
			DES_ecb3_encrypt((const_DES_cblock*)buffer_in, (const_DES_cblock*)(*output + i * 8), &ks1, &ks2, &ks3, type);
		}
		break;
	}
}


