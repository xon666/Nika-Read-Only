#pragma once

struct ConfigLoader {
    const std::string FILE_NAME = "nika.ini";
    std::vector<std::string>* lines = new std::vector<std::string>;
    long m_lastTimeFileEdited = 0;

    ConfigLoader() {
        reloadFile();
    }

    //features
    bool FEATURE_AIMBOT_ON = true;
//_    bool FEATURE_NORECOIL_ON = false;
    bool FEATURE_TRIGGERBOT_ON = true;
    bool FEATURE_SENSE_ON = false;
    bool FEATURE_ITEM_GLOW_ON = false;
    bool FEATURE_SPECTATORS_ON = true;
    bool FEATURE_SPECTATORS_SHOW_DEAD = false; //_add
    bool FEATURE_SUPER_GLIDE_ON = false;
//_    bool FEATURE_SKINCHANGER_ON = true;
//_    bool FEATURE_QUICKTURN_ON = true;
//_    bool FEATURE_PRINT_LEVELS_ON = true;
    bool FEATURE_MAP_RADAR_ON = true;
    int FEATURE_MAP_RADAR_X = 220; //_add
    int FEATURE_MAP_RADAR_Y = 220; //_add
    
    //noRecoil
//_    int NORECOIL_PITCH_REDUCTION = 15;
//_    int NORECOIL_YAW_REDUCTION = 10;

    //triggerBot
//_    int TRIGGERBOT_ZOOMED_RANGE = 180;
//_    int TRIGGERBOT_HIPFIRE_RANGE = 30;

    //sense
    int SENSE_VERBOSE = 2; //_add
    int SENSE_MAX_RANGE = 250;
    bool SENSE_SHOW_PLAYER_DISTANCES = true; //_add
    bool SENSE_SHOW_PLAYER_NAMES = false; //_add
    bool SENSE_SHOW_PLAYER_LEVELS = false; //_add
    bool SENSE_SHOW_DEAD = false; //_add

    //aimBot
    bool AIMBOT_ACTIVATED_BY_ATTACK = false;
    bool AIMBOT_ACTIVATED_BY_ADS = false;
    bool AIMBOT_ACTIVATED_BY_KEY = true;
    bool AIMBOT_ACTIVATED_BY_MOUSE = true; //_add
    float AIMBOT_SPEED = 10;
    float AIMBOT_SMOOTH = 30;
    float AIMBOT_SMOOTH_EXTRA_BY_DISTANCE = 1000;
    float AIMBOT_FOV = 10;
    float AIMBOT_FAST_AREA = 0.75f; //_add
    float AIMBOT_SLOW_AREA = 0.50f; //_add
    float AIMBOT_WEAKEN = 2; //_add
    bool AIMBOT_SPECTATORS_WEAKEN = true; //_add
    bool AIMBOT_PREDICT_BULLETDROP = true;
    bool AIMBOT_PREDICT_MOVEMENT = true;
    bool AIMBOT_ALLOW_TARGET_SWITCH = false;
    bool AIMBOT_LEGACY_MODE = false; //_add
    int AIMBOT_MAX_DISTANCE = 250;
    int AIMBOT_MIN_DISTANCE = 0;
    int AIMBOT_ZOOMED_MAX_MOVE = 20; //_add
    int AIMBOT_HIPFIRE_MAX_MOVE = 30; //_add
    int AIMBOT_MAX_DELTA = 10; //_add

    //keys
//_    std::string FEATURE_QUICKTURN_BUTTON = "XK_f";
//_    std::string FEATURE_PRINT_LEVELS_BUTTON = "XK_p";
//_    std::string FEATURE_MAP_RADAR_BUTTON = "XK_m";
//_    std::string TRIGGERBOT_PAUSE_BUTTON = "XK_z";
    std::string AIMBOT_ACTIVATION_KEY = "XK_Shift_L";
    std::string AIMBOT_FIRING_KEY = "XK_x"; //_add

    void loadVariables(std::string key, std::string val) {
        //features
        FEATURE_AIMBOT_ON = (key.compare("FEATURE_AIMBOT_ON") != 0) ? FEATURE_AIMBOT_ON : toBool(val);
//_        FEATURE_NORECOIL_ON = (key.compare("FEATURE_NORECOIL_ON") != 0) ? FEATURE_NORECOIL_ON : toBool(val);
        FEATURE_TRIGGERBOT_ON = (key.compare("FEATURE_TRIGGERBOT_ON") != 0) ? FEATURE_TRIGGERBOT_ON : toBool(val);
//_        FEATURE_SENSE_ON = (key.compare("FEATURE_SENSE_ON") != 0) ? FEATURE_SENSE_ON : toBool(val);
//_        FEATURE_ITEM_GLOW_ON = (key.compare("FEATURE_ITEM_GLOW_ON") != 0) ? FEATURE_ITEM_GLOW_ON : toBool(val);
        //noRecoil
//_        NORECOIL_PITCH_REDUCTION = (key.compare("NORECOIL_PITCH_REDUCTION") != 0) ? NORECOIL_PITCH_REDUCTION : stoi(val);
//_        NORECOIL_YAW_REDUCTION = (key.compare("NORECOIL_YAW_REDUCTION") != 0) ? NORECOIL_YAW_REDUCTION : stoi(val);
        //triggerBot
//_        TRIGGERBOT_ZOOMED_RANGE = (key.compare("TRIGGERBOT_ZOOMED_RANGE") != 0) ? TRIGGERBOT_ZOOMED_RANGE : stoi(val);
//_        TRIGGERBOT_HIPFIRE_RANGE = (key.compare("TRIGGERBOT_HIPFIRE_RANGE") != 0) ? TRIGGERBOT_HIPFIRE_RANGE : stoi(val);
//_        TRIGGERBOT_PAUSE_BUTTON = (key.compare("TRIGGERBOT_PAUSE_BUTTON") != 0) ? TRIGGERBOT_PAUSE_BUTTON : trimConstructive(val);
        //sense
        SENSE_VERBOSE = (key.compare("SENSE_VERBOSE") != 0) ? SENSE_VERBOSE : stoi(val); //_add
        SENSE_MAX_RANGE = (key.compare("SENSE_MAX_RANGE") != 0) ? SENSE_MAX_RANGE : stoi(val);
        SENSE_SHOW_PLAYER_DISTANCES = (key.compare("SENSE_SHOW_PLAYER_DISTANCES") != 0) ? SENSE_SHOW_PLAYER_DISTANCES : toBool(val); //_add
        SENSE_SHOW_PLAYER_NAMES = (key.compare("SENSE_SHOW_PLAYER_NAMES") != 0) ? SENSE_SHOW_PLAYER_NAMES : toBool(val); //_add
        SENSE_SHOW_PLAYER_LEVELS = (key.compare("SENSE_SHOW_PLAYER_LEVELS") != 0) ? SENSE_SHOW_PLAYER_LEVELS : toBool(val); //_add
        SENSE_SHOW_DEAD = (key.compare("SENSE_SHOW_DEAD") != 0) ? SENSE_SHOW_DEAD : toBool(val); //_add
        //aimBot
        AIMBOT_ACTIVATED_BY_ATTACK = (key.compare("AIMBOT_ACTIVATED_BY_ATTACK") != 0) ? AIMBOT_ACTIVATED_BY_ATTACK : toBool(val);
        AIMBOT_ACTIVATED_BY_ADS = (key.compare("AIMBOT_ACTIVATED_BY_ADS") != 0) ? AIMBOT_ACTIVATED_BY_ADS : toBool(val);
        AIMBOT_ACTIVATED_BY_KEY = (key.compare("AIMBOT_ACTIVATED_BY_KEY") != 0) ? AIMBOT_ACTIVATED_BY_KEY : toBool(val);
        AIMBOT_ACTIVATED_BY_MOUSE = (key.compare("AIMBOT_ACTIVATED_BY_MOUSE") != 0) ? AIMBOT_ACTIVATED_BY_MOUSE : toBool(val); //_add
        AIMBOT_ACTIVATION_KEY = (key.compare("AIMBOT_ACTIVATION_KEY") != 0) ? AIMBOT_ACTIVATION_KEY : trimConstructive(val);
        AIMBOT_FIRING_KEY = (key.compare("AIMBOT_FIRING_KEY") != 0) ? AIMBOT_FIRING_KEY : trimConstructive(val); //_add
        AIMBOT_SPEED = (key.compare("AIMBOT_SPEED") != 0) ? AIMBOT_SPEED : stod(val);
        AIMBOT_SMOOTH = (key.compare("AIMBOT_SMOOTH") != 0) ? AIMBOT_SMOOTH : stod(val);
        AIMBOT_SMOOTH_EXTRA_BY_DISTANCE = (key.compare("AIMBOT_SMOOTH_EXTRA_BY_DISTANCE") != 0) ? AIMBOT_SMOOTH_EXTRA_BY_DISTANCE : stod(val);
        AIMBOT_FOV = (key.compare("AIMBOT_FOV") != 0) ? AIMBOT_FOV : stod(val);
        AIMBOT_FAST_AREA = (key.compare("AIMBOT_FAST_AREA") != 0) ? AIMBOT_FAST_AREA : stod(val); //_add
        AIMBOT_SLOW_AREA = (key.compare("AIMBOT_SLOW_AREA") != 0) ? AIMBOT_SLOW_AREA : stod(val); //_add
        AIMBOT_WEAKEN = (key.compare("AIMBOT_WEAKEN") != 0) ? AIMBOT_WEAKEN : stod(val); //_add
        AIMBOT_SPECTATORS_WEAKEN = (key.compare("AIMBOT_SPECTATORS_WEAKEN") != 0) ? AIMBOT_SPECTATORS_WEAKEN : toBool(val); //_add
        AIMBOT_PREDICT_BULLETDROP = (key.compare("AIMBOT_PREDICT_BULLETDROP") != 0) ? AIMBOT_PREDICT_BULLETDROP : toBool(val);
        AIMBOT_PREDICT_MOVEMENT = (key.compare("AIMBOT_PREDICT_MOVEMENT") != 0) ? AIMBOT_PREDICT_MOVEMENT : toBool(val);
        AIMBOT_ALLOW_TARGET_SWITCH = (key.compare("AIMBOT_ALLOW_TARGET_SWITCH") != 0) ? AIMBOT_ALLOW_TARGET_SWITCH : toBool(val);
        AIMBOT_LEGACY_MODE = (key.compare("AIMBOT_LEGACY_MODE") != 0) ? AIMBOT_LEGACY_MODE : toBool(val); //_add
        AIMBOT_MAX_DISTANCE = (key.compare("AIMBOT_MAX_DISTANCE") != 0) ? AIMBOT_MAX_DISTANCE : stoi(val);
        AIMBOT_MIN_DISTANCE = (key.compare("AIMBOT_MIN_DISTANCE") != 0) ? AIMBOT_MIN_DISTANCE : stoi(val);
        AIMBOT_ZOOMED_MAX_MOVE = (key.compare("AIMBOT_ZOOMED_MAX_MOVE") != 0) ? AIMBOT_ZOOMED_MAX_MOVE : stoi(val); //_add
        AIMBOT_HIPFIRE_MAX_MOVE = (key.compare("AIMBOT_HIPFIRE_MAX_MOVE") != 0) ? AIMBOT_HIPFIRE_MAX_MOVE : stoi(val); //_add
        AIMBOT_MAX_DELTA = (key.compare("AIMBOT_MAX_DELTA") != 0) ? AIMBOT_MAX_DELTA : stoi(val); //_add
        //random
        FEATURE_SPECTATORS_ON = (key.compare("FEATURE_SPECTATORS_ON") != 0) ? FEATURE_SPECTATORS_ON : toBool(val);
        FEATURE_SPECTATORS_SHOW_DEAD = (key.compare("FEATURE_SPECTATORS_SHOW_DEAD") != 0) ? FEATURE_SPECTATORS_SHOW_DEAD : toBool(val); //_add
        FEATURE_SUPER_GLIDE_ON = (key.compare("FEATURE_SUPER_GLIDE_ON") != 0) ? FEATURE_SUPER_GLIDE_ON : toBool(val);
//_        FEATURE_SKINCHANGER_ON = (key.compare("FEATURE_SKINCHANGER_ON") != 0) ? FEATURE_SKINCHANGER_ON : toBool(val);
//_        FEATURE_QUICKTURN_ON = (key.compare("FEATURE_QUICKTURN_ON") != 0) ? FEATURE_QUICKTURN_ON : toBool(val);
//_        FEATURE_QUICKTURN_BUTTON = (key.compare("FEATURE_QUICKTURN_BUTTON") != 0) ? FEATURE_QUICKTURN_BUTTON : trimConstructive(val);
//_        FEATURE_PRINT_LEVELS_ON = (key.compare("FEATURE_PRINT_LEVELS_ON") != 0) ? FEATURE_PRINT_LEVELS_ON : toBool(val); 
//_        FEATURE_PRINT_LEVELS_BUTTON = (key.compare("FEATURE_PRINT_LEVELS_BUTTON") != 0) ? FEATURE_PRINT_LEVELS_BUTTON : trimConstructive(val);
        FEATURE_MAP_RADAR_ON = (key.compare("FEATURE_MAP_RADAR_ON") != 0) ? FEATURE_MAP_RADAR_ON : toBool(val); 
//_        FEATURE_MAP_RADAR_BUTTON = (key.compare("FEATURE_MAP_RADAR_BUTTON") != 0) ? FEATURE_MAP_RADAR_BUTTON : trimConstructive(val);
        FEATURE_MAP_RADAR_X = (key.compare("FEATURE_MAP_RADAR_X") != 0) ? FEATURE_MAP_RADAR_X : stoi(val); //_add
        FEATURE_MAP_RADAR_Y = (key.compare("FEATURE_MAP_RADAR_Y") != 0) ? FEATURE_MAP_RADAR_Y : stoi(val); //_add
    }

    void print() {
        printf("\n======================= NIKA SETTINGS LOADED =======================\n");
        //features
        printf("FEATURE_AIMBOT_ON\t\t\t\t\t%s\n", FEATURE_AIMBOT_ON ? "YES" : "NO");
//_        printf("FEATURE_NORECOIL_ON\t\t\t\t\t%s\n", FEATURE_NORECOIL_ON ? "YES" : "NO");
        printf("FEATURE_TRIGGERBOT_ON\t\t\t\t\t%s\n", FEATURE_TRIGGERBOT_ON ? "YES" : "NO");
//_        printf("FEATURE_SENSE_ON\t\t\t\t\t%s\n", FEATURE_SENSE_ON ? "YES" : "NO");
//_        printf("FEATURE_ITEM_GLOW_ON\t\t\t\t\t%s\n", FEATURE_ITEM_GLOW_ON ? "YES" : "NO");
        printf("FEATURE_SPECTATORS_ON\t\t\t\t\t%s\n", FEATURE_SPECTATORS_ON ? "YES" : "NO");
        printf("FEATURE_SPECTATORS_SHOW_DEAD\t\t\t\t%s\n", FEATURE_SPECTATORS_SHOW_DEAD ? "YES" : "NO"); //_add
        printf("FEATURE_SUPER_GLIDE_ON\t\t\t\t\t%s\n", FEATURE_SUPER_GLIDE_ON ? "YES" : "NO");
//_        printf("FEATURE_SKINCHANGER_ON\t\t\t\t\t%s\n", FEATURE_SKINCHANGER_ON ? "YES" : "NO");
//_        printf("FEATURE_QUICKTURN_ON\t\t\t\t\t%s\n", FEATURE_QUICKTURN_ON ? "YES" : "NO");
//_        printf("FEATURE_QUICKTURN_BUTTON\t\t\t\t%s\n", FEATURE_QUICKTURN_BUTTON.c_str());
//_        printf("FEATURE_PRINT_LEVELS_ON\t\t\t\t\t%s\n", FEATURE_PRINT_LEVELS_ON ? "YES" : "NO");
//_        printf("FEATURE_PRINT_LEVELS_BUTTON\t\t\t\t%s\n", FEATURE_PRINT_LEVELS_BUTTON.c_str());
        printf("FEATURE_MAP_RADAR_ON\t\t\t\t\t%s\n", FEATURE_MAP_RADAR_ON ? "YES" : "NO");
//_        printf("FEATURE_MAP_RADAR_BUTTON\t\t\t\t%s\n", FEATURE_MAP_RADAR_BUTTON.c_str());
        printf("FEATURE_MAP_RADAR_X\t\t\t\t\t%d\n", FEATURE_MAP_RADAR_X); //_add
        printf("FEATURE_MAP_RADAR_Y\t\t\t\t\t%d\n", FEATURE_MAP_RADAR_Y); //_add
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        //noRecoil
//_        printf("NORECOIL_PITCH_REDUCTION\t\t\t\t%d\n", NORECOIL_PITCH_REDUCTION);
//_        printf("NORECOIL_YAW_REDUCTION\t\t\t\t\t%d\n", NORECOIL_YAW_REDUCTION);
//_        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        //triggerBot
//_        printf("TRIGGERBOT_ZOOMED_RANGE\t\t\t\t\t%d\n", TRIGGERBOT_ZOOMED_RANGE);
//_        printf("TRIGGERBOT_HIPFIRE_RANGE\t\t\t\t%d\n", TRIGGERBOT_HIPFIRE_RANGE);
//_        printf("TRIGGERBOT_PAUSE_BUTTON\t\t\t\t\t%s\n", TRIGGERBOT_PAUSE_BUTTON.c_str());
//_        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        //sense
        printf("SENSE_VERBOSE\t\t\t\t\t\t%d\n", SENSE_VERBOSE); //_add
        printf("SENSE_MAX_RANGE\t\t\t\t\t\t%d\n", SENSE_MAX_RANGE);
        printf("SENSE_SHOW_PLAYER_DISTANCES\t\t\t\t%s\n", SENSE_SHOW_PLAYER_DISTANCES ? "YES" : "NO"); //_add
        printf("SENSE_SHOW_PLAYER_NAMES\t\t\t\t\t%s\n", SENSE_SHOW_PLAYER_NAMES ? "YES" : "NO"); //_add
        printf("SENSE_SHOW_PLAYER_LEVELS\t\t\t\t%s\n", SENSE_SHOW_PLAYER_LEVELS ? "YES" : "NO"); //_add
        printf("SENSE_SHOW_DEAD\t\t\t\t\t\t%s\n", SENSE_SHOW_DEAD ? "YES" : "NO"); //_add
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        //aimBot
        printf("AIMBOT_ACTIVATED_BY_ATTACK\t\t\t\t%s\n", AIMBOT_ACTIVATED_BY_ATTACK ? "YES" : "NO");
        printf("AIMBOT_ACTIVATED_BY_ADS\t\t\t\t\t%s\n", AIMBOT_ACTIVATED_BY_ADS ? "YES" : "NO");
        printf("AIMBOT_ACTIVATED_BY_KEY\t\t\t\t\t%s\n", AIMBOT_ACTIVATED_BY_KEY ? "YES" : "NO");
        printf("AIMBOT_ACTIVATED_BY_MOUSE\t\t\t\t%s\n", AIMBOT_ACTIVATED_BY_MOUSE ? "YES" : "NO"); //_add
        printf("AIMBOT_ACTIVATION_KEY\t\t\t\t\t%s\n", AIMBOT_ACTIVATION_KEY.c_str());
        printf("AIMBOT_FIRING_KEY\t\t\t\t\t%s\n", AIMBOT_FIRING_KEY.c_str()); //_add
        printf("AIMBOT_SPEED\t\t\t\t\t\t%.4f\n", AIMBOT_SPEED);
        printf("AIMBOT_SMOOTH\t\t\t\t\t\t%.4f\n", AIMBOT_SMOOTH);
        printf("AIMBOT_SMOOTH_EXTRA_BY_DISTANCE\t\t\t\t%.4f\n", AIMBOT_SMOOTH_EXTRA_BY_DISTANCE);
        printf("AIMBOT_FOV\t\t\t\t\t\t%.2f\n", AIMBOT_FOV);
        printf("AIMBOT_FAST_AREA\t\t\t\t\t%.2f\n", AIMBOT_FAST_AREA); //_add
        printf("AIMBOT_SLOW_AREA\t\t\t\t\t%.2f\n", AIMBOT_SLOW_AREA); //_add
        printf("AIMBOT_WEAKEN\t\t\t\t\t\t%.2f\n", AIMBOT_WEAKEN); //_add
        printf("AIMBOT_SPECTATORS_WEAKEN\t\t\t\t%s\n", AIMBOT_SPECTATORS_WEAKEN ? "YES" : "NO"); //_add
        printf("AIMBOT_PREDICT_BULLETDROP\t\t\t\t%s\n", AIMBOT_PREDICT_BULLETDROP ? "YES" : "NO");
        printf("AIMBOT_PREDICT_MOVEMENT\t\t\t\t\t%s\n", AIMBOT_PREDICT_MOVEMENT ? "YES" : "NO");
        printf("AIMBOT_ALLOW_TARGET_SWITCH\t\t\t\t%s\n", AIMBOT_ALLOW_TARGET_SWITCH ? "YES" : "NO");
        printf("AIMBOT_LEGACY_MODE\t\t\t\t\t%s\n", AIMBOT_LEGACY_MODE ? "YES" : "NO"); //_add
        printf("AIMBOT_MAX_DISTANCE\t\t\t\t\t%d\n", AIMBOT_MAX_DISTANCE);
        printf("AIMBOT_MIN_DISTANCE\t\t\t\t\t%d\n", AIMBOT_MIN_DISTANCE);
        printf("AIMBOT_ZOOMED_MAX_MOVE\t\t\t\t\t%d\n", AIMBOT_ZOOMED_MAX_MOVE); //_add
        printf("AIMBOT_HIPFIRE_MAX_MOVE\t\t\t\t\t%d\n", AIMBOT_HIPFIRE_MAX_MOVE); //_add
        printf("AIMBOT_MAX_DELTA\t\t\t\t\t%d\n", AIMBOT_MAX_DELTA); //_add
        printf("====================================================================\n\n");
    }

    void reloadFile() {
        if (loadFileIntoVector()) {
            parseLines();
            print(); 
            printLogo();
        }
    }
    void parseLines() {
        for (int i = 0; i < lines->size(); i++) {
            std::vector<std::string> lineParts = split(lines->at(i));
            // line key
            std::string key(lineParts.at(0));
            trim(key);
            if (key.empty()) throw "Cannot parse the config. Bad key";
            // line value
            std::string value(lineParts.at(1));
            trim(value);
            if (value.empty()) throw "Cannot parse the config. Bad value";
            loadVariables(key, value);
        }
    }
    void trim(std::string& s) {
        ltrim(s);
        rtrim(s);
    }
    void ltrim(std::string& s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
            { return !std::isspace(ch); }));
    }
    void rtrim(std::string& s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
            { return !std::isspace(ch); })
            .base(),
            s.end());
    }
    bool loadFileIntoVector() {
        struct stat result;
        if (stat(FILE_NAME.c_str(), &result) == 0) {
            long modTime = result.st_mtime;
            bool fileNeedsReload = modTime > m_lastTimeFileEdited;
            m_lastTimeFileEdited = modTime;
            if (!fileNeedsReload) return false;
        }
        lines->clear();
        std::string str;
        std::ifstream myFile(FILE_NAME);
        while (getline(myFile, str)) {
            trim(str);
            if (str.empty()) continue;
            if (str.rfind("#", 0) == 0) continue;
            lines->push_back(str);
        }
        myFile.close();
        return true;
    }
    bool toBool(std::string str) {
        if (toLowerCase(str) == "y") return true;
        if (toLowerCase(str) == "n") return false;
        if (toLowerCase(str) == "yes") return true;
        if (toLowerCase(str) == "no") return false;
        if (toLowerCase(str) == "1") return true;
        if (toLowerCase(str) == "0") return false;
        throw  std::invalid_argument("Cannot parse string to boolean: " + str);
    }
    std::string trimConstructive(std::string& s) {
        ltrim(s);
        rtrim(s);
        return s;
    }
    std::vector<std::string> split(std::string s) {
        std::stringstream ss(s);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> tokens(begin, end);
        return tokens;
    }
    std::string toLowerCase(const std::string& input) {
        std::string result = input;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

    void printLogo(){
        std::cout << "\033[1;33m";
        std::cout << " .--..--..--..--..--..--..--..--..--..--..--..--..--..--.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"(/ .. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"(\ \/\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ \/ /)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"( \/ /`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'\/ /)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"( / /\                                                / /\)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"(/ /\ \          ,--.             ,--.               / /\ \)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"(\ \/ /        ,--.'|  ,---,  ,--/  /|  ,---,,       \ \/ /)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"( \/ /     ,--,:  : ,`--.' ,---,': / ' '  .'  :       \/ /)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"( / /\  ,`--.'`|  ' |   :  :   : '/ / /  ;     \      / /\)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"(/ /\ \ |   :  :  | :   |  |   '   , :  :       :    / /\ \)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"(\ \/ / :   |   \ | |   :  '   |  /  :  |   /\   \   \ \/ /)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"( \/ /  |   : '  '; '   '  |   ;  ;  |  :  ' ;.   :   \/ /)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"( / /\  '   ' ;.    |   |  :   '   \ |  |  ;/  \   \  / /\)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"(/ /\ \ |   | | \   '   :  |   |    ''  :  | \  \ ,' / /\ \)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"(\ \/ / '   : |  ; .|   |  '   : |.  |  |  '  '--'   \ \/ /)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"( \/ /  |   | '`--' '   :  |   | '_\.|  :  :          \/ /)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"( / /\  '   : |     ;   |.''   : |   |  | ,'          / /\)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"(/ /\ \ ;   |.'     '---'  ;   |,'   `--''           / /\ \)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"(\ \/ / '---'              '---'                     \ \/ /)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"( \/ /                                                \/ /)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"( / /\.--..--..--..--..--..--..--..--..--..--..--..--./ /\)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"(/ /\ \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \/\ \)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"(\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `' /)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(69));
        std::cout << R"( `--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--')" << std::endl;
        std::cout << "\033[0m"; 
    }
};
