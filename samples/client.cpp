#include <ifaddrs.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <errno.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <iostream>
using namespace std;
/* -Obtain-IPv4-server-ip-address-to-connect-from-client--------------------
 * PARAMETER		PARAMETER_DESCRIPTION
 * char* IPv4		Obtain IPv4 at current system to connect at server.
 * RETURN_TYPE
 * void			N/A
 * FUNCTION		FUNCTION_DESCRIPTION
 * GetIPv4		This function defined at GetIPv4.cpp
 *			GetIPv4.o used later by client executable for compilation.
 */
void GetIPv4( char* IPv4)
{
	struct ifaddrs * ifAddrStruct=NULL;
	struct ifaddrs * ifa=NULL;
	void * tmpAddrPtr=NULL;
	getifaddrs(&ifAddrStruct);
	for (ifa = ifAddrStruct; NULL != ifa; ifa=ifa->ifa_next)
	{
		if( !ifa->ifa_addr )
		{
			continue;
		}
		if( AF_INET == ifa->ifa_addr->sa_family )
		{
			// check it is IP4
			// is a valid IP4 Address
			tmpAddrPtr=&((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
			char addressBuffer[INET_ADDRSTRLEN] = { '\0' };
			inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
			if( 0 != strcmp( "lo", ifa->ifa_name ) )
			{
				string curIPv4 = IPv4;
				curIPv4.resize(23, ' ');
				cout << "IPv4: " << curIPv4;
				cout << " addressBuffer: " << addressBuffer << "\n";
				strcpy( IPv4, addressBuffer);
				break;
			}
			else
			{
				// cout << "Being lo addressBuffer: " << addressBuffer << "\n";
			}
		}
	}
	if( NULL != ifAddrStruct )
	{
		freeifaddrs( ifAddrStruct );
		ifAddrStruct=NULL;
	}
	return;
} /* void GetIPv4( char* IPv4) */
/* ---------------------------------------------------------- *
*  * create_socket() creates the socket & TCP-connect to server *
*   * ---------------------------------------------------------- */
int create_socket(char url_str[], BIO *out)
{
	int sockfd = 0;
	char hostname[256] = "";
	char    portnum[6] = "9017";
	char      proto[20] = "";
	char      *tmp_ptr = NULL;
	int           port = 9017;
	struct hostent *host;
	struct sockaddr_in dest_addr;
	/* ---------------------------------------------------------- *
	*    * Remove the final / from url_str, if there is one           *
	*       * ---------------------------------------------------------- */
	if(url_str[strlen(url_str)] == '/')
	url_str[strlen(url_str)] = '\0';
	/* ---------------------------------------------------------- *
	*    * the first : ends the protocol string, i.e. http            *
	*       * ---------------------------------------------------------- */
	// strncpy(proto, url_str, (strchr(url_str, ':')-url_str));
	strcpy(proto, url_str);
	/* ---------------------------------------------------------- *
	*    * the hostname starts after the "://" part                   *
	*       * ---------------------------------------------------------- */
	// strncpy(hostname, strstr(url_str, "://")+3, sizeof(hostname));
	strcpy(hostname, url_str);
	/* ---------------------------------------------------------- *
	*    * if the hostname contains a colon :, we got a port number   *
	*       * ---------------------------------------------------------- */
	if( strchr(hostname, ':') )
	{
		tmp_ptr = strchr(hostname, ':');
		/* the last : starts the port number, if avail, i.e. 9017 */
		strncpy(portnum, tmp_ptr+1,  sizeof(portnum));
		*tmp_ptr = '\0';
	}
	port = atoi(portnum);
	if( NULL == (host = gethostbyname(hostname) ) )
	{
		BIO_printf(out, "Error: Cannot resolve hostname %s.\n",  hostname);
		abort();
	}
	/* ---------------------------------------------------------- *
	*    * create the basic TCP socket                                *
	*       * ---------------------------------------------------------- */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	dest_addr.sin_family=AF_INET;
	dest_addr.sin_port=htons(port);
	dest_addr.sin_addr.s_addr = *(long*)(host->h_addr);
	/* ---------------------------------------------------------- *
	*    * Zeroing the rest of the struct                             *
	*       * ---------------------------------------------------------- */
	memset(&(dest_addr.sin_zero), '\0', 8);
	tmp_ptr = inet_ntoa(dest_addr.sin_addr);
	/* ---------------------------------------------------------- *
	*    * Try to make the host connect here                          *
	*       * ---------------------------------------------------------- */
	if( -1 == connect(sockfd, (struct sockaddr *) &dest_addr, sizeof(struct sockaddr) ) )
	{
		BIO_printf(out, "Error: Cannot connect to host %s [%s] on port %d.\n", hostname, tmp_ptr, port);
	}
	return sockfd;
}
int main()
{
	errno = 0;
	for( int i = 0; 2> i; ++i)
	{
		OpenSSL_add_all_algorithms();
		ERR_load_BIO_strings();
		ERR_load_crypto_strings();
		SSL_load_error_strings();
		SSL_library_init();
		const SSL_METHOD* method =  SSLv23_client_method();
		SSL_CTX*              ctx = NULL;
		ctx = SSL_CTX_new(method);
		int err_error_string_Ret = ERR_get_error();
		if ( NULL == ctx )
		{
			char buf[1024] = { '\0' };
			sprintf( buf, "%s", strerror(errno) );
			cout << "ctx error strerror(errno): " << buf << "\n";
			cout << "ctx error ERR_get_error(): " << err_error_string_Ret << "\n";
			cout << "ctx error ERR_error_string(ERR_get_error()): " << ERR_error_string( err_error_string_Ret, NULL) << "\n";
			cout << "ctx error ERR_error_string(ERR_get_error()): " << ERR_error_string( err_error_string_Ret, NULL) << "\n";
			return 0;
		}
		SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2);
		SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2);
		SSL* ssl = SSL_new(ctx);
		char IPv4[1024] = { '\0' };
		GetIPv4( IPv4 );
		int server = 0;
		BIO               *outbio = NULL;
		outbio  = BIO_new_fp(stdout, BIO_NOCLOSE);
		BIO              *certbio = NULL;
		certbio = BIO_new(BIO_s_file());
		BIO_push( outbio,certbio );
		server = create_socket(IPv4, outbio);
		// int SSL_set_fdRet = SSL_set_fd(ssl, server); // Working case
		int SSL_set_fdRet = SSL_set_fd(ssl, server+1); // not working case
		if ( 0 == SSL_set_fdRet )
		{
			int currentErr = SSL_get_error(ssl, SSL_set_fdRet);
			cout << "SSL_set_fd error ERR_get_error(): " << err_error_string_Ret << "\n";
			cout << "SSL_set_fd error ERR_error_string( " << err_error_string_Ret << " ) : " << ERR_error_string( err_error_string_Ret, NULL) << "\n";
			cout << "SSL_set_fd error SSL_get_error: " << currentErr << "\n";
			cout << "SSL_set_fd error ERR_error_string( " << currentErr << "): " << ERR_error_string( currentErr, NULL) << "\n";
			char buf[1024] = { '\0' };
			sprintf( buf, "%s", strerror(errno) );
			cout << "SSL_set_fd error 03 strerror(errno): " << buf << "\n";
			continue;
		}
		int SSL_connectRet = SSL_connect( ssl );
		// Corect way:
		err_error_string_Ret = ERR_get_error();
		cout << "SSL_connectRet: " << SSL_connectRet << "\n";
		if ( 0 >= SSL_connectRet )
		{
			char buf[1024] = { '\0' };
			sprintf( buf, "%s", strerror(errno) );
			cout << "SSL_connect error 00 strerror(errno): " << buf << "\n";
			int currentErr = SSL_get_error(ssl, SSL_connectRet);
			cout << "SSL_connect error ERR_get_error(): " << err_error_string_Ret << "\n";
			cout << "SSL_connect error ERR_error_string( " << err_error_string_Ret << " ) : " << ERR_error_string( err_error_string_Ret, NULL) << "\n";
			cout << "SSL_connect error SSL_get_error: " << currentErr << "\n";
			cout << "SSL_connect error ERR_error_string( " << currentErr << "): " << ERR_error_string( currentErr, NULL) << "\n";
			sprintf( buf, "%s", strerror(errno) );
			cout << "SSL_connect error 03 strerror(errno): " << buf << "\n";
		}
		if ( NULL != ssl )
		{
			delete ssl;
			ssl = NULL;
		}
	}
	return 0;
}
