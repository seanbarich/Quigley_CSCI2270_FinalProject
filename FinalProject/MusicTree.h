#ifndef MUSICTREE_H
#define MUSICTREE_H

struct SongNode{
	std::string artist;
	std::string name;
	std::string album;
  SongNode *parent;
  SongNode *left;
  SongNode *right;

	SongNode(){};

	SongNode(std::string _artist, std::string _name, std::string _album)
	{
		artist = _artist;
		name = _name;
		album = _album;
		parent = NULL;
		left = NULL;
		right = NULL;
	}

};

class MusicTree
{

    public:
        MusicTree();
        ~MusicTree();
				void printMusicLibrary();
				int countSongNodes();
				void addSongNode(std::string artist, std::string name, std::string album);
				void checkForArtist(std::string artist);
				void populateXML();
				void findSong(std::string name);
				void printAlbum(std::string album);

    protected:

    private:
				bool findSong(SongNode *node, std::string name);
				bool printAlbum(SongNode *node, std::string album);
				void printMusicLibrary(SongNode *node);
				int countSongNodes(SongNode *node);
				SongNode *roo;
};

#endif // MUSICTREE_H
