#include <iostream>

using namespace std;

/**
 * Serialize / Deserialize interface
 */
class ISerializable
{
public:
    /**
     * シリアライズ処理を実現する
     * @param data シリアライズデータとして append する先
     * @return シリアライズ結果
     */
    virtual ostream serialize(ostream data);

    /**
     * デシリアライズ処理を実現する
     */
    virtual void deserialize(ostream data) = 0;

    virtual ~ISerializable(){};
};
