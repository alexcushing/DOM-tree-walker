/* 
 * 
 */

#include "CreateDomDocument.h"

using namespace std;
/*
 * Global variables for easy access 
 */
static char* gXPathExpression = 0;
static XMLCh* gOutputEncoding = 0;
static bool gUseFilter = false;
static char* goutputfile = 0;
static bool gFormatPrettyPrint = true;
static bool gSplitCdataSections = true;
static bool gDiscardDefaultContent = true;
static bool gWriteBOM = false;

/*
 * Xstr constructors
 */
XStr::XStr(const char* const toTranscode) {
   // Call the private transcoding method
   fUnicodeForm = XMLString::transcode(toTranscode);
}
XStr::~XStr() {
   XMLString::release(&fUnicodeForm);
}

/**
* @purpose GETTER function to retrieve XMLCh
* @return - fUnicodeForm
*/
const XMLCh* XStr::unicodeForm() const {
   return fUnicodeForm;
}

/**
 * The beginning of the CreateDomDocument function
 * This function creates the XML Dom Document in memory, as according to Professor Heine's criteria
 * 
 */
CreateDOMDocument::CreateDOMDocument() {

   XMLPlatformUtils::Initialize();

   //  Nest entire test in an inner block.
   //  The tree we create below is the same that the XercesDOMParser would
   //  have created, except that no whitespace text nodes would be created.


   DOMImplementation* impl = DOMImplementationRegistry::getDOMImplementation(X("Core"));
   //    /**
   //     * Declare DOMLSSerializer
   //     */
   //    DOMLSSerializer *theSerializer = ((DOMImplementationLS*) impl)->createLSSerializer();

   if (impl != NULL) {
      DOMDocument* doc = impl->createDocument(
              0, // root element namespace URI.
              X("Music-Library"), // root element name
              0); // document type object (DTD).

    DOMElement* rootElem = doc->getDocumentElement();
    rootElem->setAttribute(X("idea"), X("great"));
    rootElem->setAttribute(X("new"),X("attribute"));
    rootElem->setAttribute(X("third"),X("attribute"));

    //recording
    DOMElement*  recElem = doc->createElement(X("recording"));
    recElem->setAttribute(X("id"),X("eoih9w83usg08e49"));
    rootElem->appendChild(recElem);
    
    //title
    DOMElement* titleElem = doc->createElement(X("title"));
    titleElem->setTextContent(X("My Dark Beautiful Twisted Fantasy"));
    rootElem->appendChild(titleElem);
    
    //song1
    DOMElement* song1Elem = doc->createElement(X("One"));
    song1Elem->setTextContent(X("Dark Fantasy"));
    rootElem->appendChild(song1Elem);
    song1Elem->setAttribute(X("rating"), X("8/10"));
    song1Elem->setAttribute(X("description"), X("can we get much higher"));
    song1Elem->setAttribute(X("idea"), X("great"));
    
    
    //song2
    DOMElement* song2Elem = doc->createElement(X("Two"));
    song2Elem->setTextContent(X("Gorgeous"));
    rootElem->appendChild(song2Elem);
    song2Elem->setAttribute(X("rating"), X("10/10"));
    song2Elem->setAttribute(X("description"), X("I can feel it dripping it away from me"));
    song2Elem->setAttribute(X("idea"), X("great"));
    
    //song2 features
    DOMElement* song2Features = doc->createElement(X("Features"));
    song2Features->setTextContent(X("Kid Cudi, Raekwon"));
    song2Elem->appendChild(song2Features);
    DOMElement* song2Colors = doc->createElement(X("Color"));
    song2Colors->setTextContent(X("Red"));
    song2Elem->appendChild(song2Colors); 
    DOMElement* song2SColors_2 = doc->createElement(X("Second_Color"));
    song2SColors_2 ->setTextContent(X("White"));
    song2Elem->appendChild(song2SColors_2); 
    
    //song3
    DOMElement* song3Elem = doc->createElement(X("Three"));
    song3Elem->setTextContent(X("Power"));
    rootElem->appendChild(song3Elem);
    song3Elem->setAttribute(X("rating"), X("9/10"));
    song3Elem->setAttribute(X("description"), X("uhhhh YEAAAAH"));
    song3Elem->setAttribute(X("idea"), X("great"));
    
    /*
    //song3 rating
    DOMElement* songRating = doc->createElement(X("Rating"));
    song3Rating->setTextContent(X("Uhhhh YEAAAAH"));
    song3Elem->appendChild(song3Rating);
    */
    
    //song4
    DOMElement* song4Elem = doc->createElement(X("Four"));
    song4Elem->setTextContent(X("All Of The Lights"));
    rootElem->appendChild(song4Elem);
    song4Elem->setAttribute(X("rating"), X("5/10"));
    song4Elem->setAttribute(X("description"), X("the music video gave me a seizure"));
    song4Elem->setAttribute(X("idea"), X("great"));
      
    //song4 features
    DOMElement* song4Features = doc->createElement(X("Features"));
    song4Features->setTextContent(X("Kid Cudi, Rihanna"));
    song4Elem->appendChild(song4Features);
    DOMElement* song4Colors = doc->createElement(X("Color"));
    song4Colors->setTextContent(X("Red"));
    song4Elem->appendChild(song4Colors); 
    DOMElement* song4SColors = doc->createElement(X("Second_Color"));
    song4SColors ->setTextContent(X("White"));
    song4Elem->appendChild(song4SColors ); 
    /*
    //song4 rating
    DOMElement* songRating = doc->createElement(X("Rating"));
    song4Rating->setTextContent(X("its ok music video gave me seizures"));
    song4Elem->appendChild(song4Rating);
    */
    
    //song5
    DOMElement* song5Elem = doc->createElement(X("Five"));
    song5Elem->setTextContent(X("Monster"));
    rootElem->appendChild(song5Elem);
    song5Elem->setAttribute(X("rating"), X("10/10"));
    song5Elem->setAttribute(X("description"), X("50k for a verse no album out"));
    song5Elem->setAttribute(X("idea"), X("great"));
    
    //song5 features
    DOMElement* song5Features = doc->createElement(X("Features"));
    song5Features->setTextContent(X("Nicki Minaj, Jay Z, Rick Ross, Bon Iver"));
    song5Elem->appendChild(song5Features);
    DOMElement* song5Colors = doc->createElement(X("Color"));
    song5Colors->setTextContent(X("Red"));
    song5Elem->appendChild(song5Colors); 
    DOMElement* song5SColors = doc->createElement(X("Second_Color"));
    song5SColors ->setTextContent(X("White"));
    song5Elem->appendChild(song5SColors ); 
    
    //song6
    DOMElement* song6Elem = doc->createElement(X("Six"));
    song6Elem->setTextContent(X("So Appalled"));
    rootElem->appendChild(song6Elem);
    song6Elem->setAttribute(X("rating"), X("11/10"));
    song6Elem->setAttribute(X("description"), X("MAN THIS ISH IS ____"));
    song6Elem->setAttribute(X("idea"), X("great"));
    
    //song6 features
    DOMElement* song6Features = doc->createElement(X("Features"));
    song6Features->setTextContent(X("Jay Z, Pusha T, Cyhi the Prynce, Swizz Beatz, RZA"));
    song6Elem->appendChild(song6Features);
    DOMElement* song6Colors = doc->createElement(X("Color"));
    song6Colors->setTextContent(X("Red"));
    song6Elem->appendChild(song6Colors); 
    DOMElement* song6SColors = doc->createElement(X("Second_Color"));
    song6SColors ->setTextContent(X("White"));
    song6Elem->appendChild(song6SColors ); 
    
    
    //song7
    DOMElement* song7Elem = doc->createElement(X("Seven"));
    song7Elem->setTextContent(X("Devil In A New Dress"));
    rootElem->appendChild(song7Elem);
    song7Elem->setAttribute(X("rating"), X("112/10"));
    song7Elem->setAttribute(X("description"), X("we ain't married but I need some consummation"));
    song7Elem->setAttribute(X("idea"), X("great"));
    
    //song7 features/children
    DOMElement* song7Features = doc->createElement(X("Features"));
    song7Features->setTextContent(X("Rick Ross"));
    song7Elem->appendChild(song7Features); 
    
    DOMElement* song7Colors = doc->createElement(X("Color"));
    song7Colors->setTextContent(X("Red"));
    song7Elem->appendChild(song7Colors); 
    
    DOMElement* song7SColors = doc->createElement(X("Second_Color"));
    song7SColors ->setTextContent(X("White"));
    song7Elem->appendChild(song7SColors ); 
    
    
    //song8
    DOMElement* song8Elem = doc->createElement(X("Eight"));
    song8Elem->setTextContent(X("Runaway"));
    rootElem->appendChild(song8Elem);
    song8Elem->setAttribute(X("rating"), X("8/10"));
    song8Elem->setAttribute(X("description"), X("kanye makes strange noises for a few minutes"));
    song8Elem->setAttribute(X("idea"), X("great"));
    
    //song8 features
    DOMElement* song8Features = doc->createElement(X("Features"));
    song8Features->setTextContent(X("Pusha T"));
    song8Elem->appendChild(song8Features); 
    
    //song9
    DOMElement* song9Elem = doc->createElement(X("Nine"));
    song9Elem->setTextContent(X("Blame Game"));
    rootElem->appendChild(song9Elem);
    song9Elem->setAttribute(X("rating"), X("8/10"));
    song9Elem->setAttribute(X("description"), X("lets play the blame, game, I love memes"));
    song9Elem->setAttribute(X("idea"), X("great"));

    //song10
    DOMElement* song10Elem = doc->createElement(X("Ten"));
    song10Elem->setTextContent(X("Hell Of A Life"));
    rootElem->appendChild(song10Elem);
    song10Elem->setAttribute(X("rating"), X("6/10"));
    song10Elem->setAttribute(X("description"), X("alexs favorite song I don't get it"));
    song10Elem->setAttribute(X("idea"), X("great"));
    
    //song11
    DOMElement* song11Elem = doc->createElement(X("Eleven"));
    song11Elem->setTextContent(X("Lost In The World"));
    rootElem->appendChild(song11Elem);
    song11Elem->setAttribute(X("rating"), X("7/10"));
    song11Elem->setAttribute(X("description"), X("bon iver is cool"));
    song11Elem->setAttribute(X("idea"), X("great"));

      // Function which counts the elements
      const XMLSize_t elementCount = doc->getElementsByTagName(X("*"))->getLength();
      XERCES_STD_QUALIFIER cout << "The tree just created contains: " << elementCount
              << " elements." << XERCES_STD_QUALIFIER endl << endl;

      cout << "----------------------------------------------------------------\n" << endl;

      //Print to terminal the XML document
     PrintXML(doc); // the print function get run time error.

      cout << "----------------------------------------------------------------\n";

    //  TreeWalker(rootElem, doc);

      //doc->release();
   }

   // **********************************
  // XMLPlatformUtils::Terminate();
}

/**
 * This function prints the XML document which has been created and stored in memory
 * Most of this code was retrieved from Professor Heines DOMPrint function
 */
void CreateDOMDocument::PrintXML(DOMDocument* doc) {

    XercesDOMParser *parser = new XercesDOMParser;
    //parser->parse(doc);
    // get a serializer, an instance of DOMLSSerializer
    XMLCh tempStr[3] = {chLatin_L, chLatin_S, chNull};
    DOMImplementation *impl          = DOMImplementationRegistry::getDOMImplementation(tempStr);
    DOMLSSerializer   *theSerializer = ((DOMImplementationLS*)impl)->createLSSerializer();
    DOMLSOutput       *theOutputDesc = ((DOMImplementationLS*)impl)->createLSOutput();
    
    theSerializer->setNewLine(X("\n"));
    
    //prints it "pretty"
    if(theSerializer->getDomConfig()->canSetParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true)){
        theSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true);
    }
    
    
    
    XMLFormatTarget *myFormTarget = new StdOutFormatTarget();
    theOutputDesc->setByteStream(myFormTarget);
    // set user specified output encoding
    theOutputDesc->setEncoding(gOutputEncoding);
    
    //writes the serializer 
    theSerializer->write(doc, theOutputDesc);
    
    theOutputDesc->release();
    theSerializer->release();
}
/*
 * Function which walks through the DOMDoc in memory and display's it's Metadata 
 */
void CreateDOMDocument::TreeWalker(DOMElement* rootElem, DOMDocument* doc) {

   return;
}