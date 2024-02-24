/**
* @author: weijie
* @date: 24 feb 2024
* @brief: wrapper for window class, try to make it switchable from
* using SDL_Window to gflw
*/

namespace PonkoEnv
{
	/**
	* @breif: making this a singleton since it does make sense for this to be
	* a singleton and also to just practice and put into application the 
	* singleton design pattern
	* 
	* singleton - a class with only one given instance and is used via reference
	*/
	class PK_Window
	{
	public:
		PK_Window(PK_Window const&) = delete; // To prevent copy constructor to
											  // making more then 1 instance

		PK_Window& GetInstance();
	private:
		PK_Window() {}; // private to prevent creation of new instances

		static PK_Window s_Instance;
	};
}