#include <iostream>
#include "Tokenizer/Tokenizer.h"


static const char MESSAGE[] = { "Hello world" };
static const char MESSAGE2[] = { "XHello world" };

int main(int argc, char *argv[])
{
    Tokenizer::Decoder decoder;
    Tokenizer::Coder coder;
    /*coder.code(MESSAGE, sizeof(MESSAGE));
    decoder.feed(coder.data(), coder.size());
    coder.code(MESSAGE2, sizeof(MESSAGE2));
    decoder.feed(coder.data(), coder.size());

    while (decoder.decode())
    {
        // data frame-u:        decoder.data()
        // velkost dat frame-u: decoder.size()
        decoder.reset();
    }

    */

    // zacatek funbkce ready read
    const char * datagram = nullptr; // data ktore som prijal z TCP
    const size_t datagramLength = 0; // velkost dat prijatych z TCP

    decoder.feed(datagram, datagramLength);
    while (decoder.decode())
    {
        // data prijata a zpracovana tokenizerem
        const char * data = decoder.data();
        const size_t length = decoder.size();
        // reset pro dekodovani dalsiho ramce
        decoder.reset();
    }

    return 0;
}
