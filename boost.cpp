#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;          //<--- brings the tcp class into the current scope for easy access
using namespace std;
string site;

int booster()
{
    cout << "Enter target host: ";
    cin >> site;
    // try is great for error handling and catching mishaps
    try{
        //Define our socket here
        io_service io_service;   //<--- creates an io_service object
        tcp::socket socket(io_service); // Creates and represents the TCP socket

        //resolve hostname and service
        tcp::resolver resolver(io_service);     //tcp::resolver is used to resolve DNS and service names
        tcp::resolver::query query(site.c_str(), "80"); //Input URL amd Port
        tcp::resolver::iterator endpoint_iterator =resolver.resolve(query); //Resolves the query into a list of endpoints

        //create and establish connection
        //tcp::resolver socket(io_service);
        boost::asio::connect(socket,endpoint_iterator);

        //HTTP GET request                                  //Connection: close tells the server to close connection after response
        string request= "GET / HTTP/1.1\r\n"
                        "Host: "+site+"\r\n"
                        "Connection: close\r\n\r\n";

        //Sending the HTTP request
        boost::asio::write(socket, boost ::asio::buffer(request));

       //streambuf can be used with I/O streams so we make a response variable with it
        boost::asio::streambuf response;
         //reads until a buffer delimiter is found {"\r\n"}
        boost::asio::read_until(socket, response, "\r\n");

        //check that response is ok by parsing the status line
        string http_version;
        unsigned int status_code;
        string status_message;
        //creates an input stream from the buffer
        istream response_stream(&response);
                        //↘️ reads HTTP version  //↙️ reads status message 
        response_stream >> http_version >> status_code;
        getline(response_stream, status_message);

        //read response body
        boost::system::error_code error;

        while (boost::asio::read(socket,response,boost::asio::transfer_at_least(1), error)){
        }if (error != boost::asio::error::eof){
            throw boost::system::system_error(error);
        }
        istream response_stream2(&response);
        string body(istreambuf_iterator<char>(response_stream2), {});
        cout << "Response: " << body << endl;
    }catch ( exception& e){
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}

int main(){
    booster();
}
