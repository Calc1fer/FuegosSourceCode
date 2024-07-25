#pragma once
#include "framework/GameObject.h"
#include "Framework/Animation.h"
#include "framework/VectorHelper.h"
#include "Framework/AudioManager.h"
#include "FireBallManager.h"
#include "PickupManager.h"
#include "PortalManager.h"
#include "windows.h"

class Player :
    public GameObject
{
public:

    Player();
    ~Player();

    void update(float dt) override;
    void handleInput(float dt) override;
    std::vector<Fireball>* getAmmo();
    void collisionResponseEnemy(GameObject* collider);
    void collisionResponseWorld(GameObject* collider);
    void collisionResponseObstacle(GameObject* collider);
    void collisionResponsePickup(GameObject* collider);
    void collisionResponseFragment(GameObject* collider);
    void collisionResponsePortal(GameObject* collider);
    void setTakeDamage();
    int getFragCount();
    int getHealth();
    void displayHealth();
    void displayAmmo();
    void displayFragments();
    void reset();
    void render(sf::RenderWindow* window);

private:
    //variables for player class including animations and functions for user input
    Animation idle;
    Animation run;
    Animation shield;
    Animation idleShield;
    Animation attack;
    Animation takingDamage;
    Animation death;
    Animation jump;
    Animation* currentAnimation;

    AudioManager audio;

    float scale;
    sf::Vector2f colliderPos;

    sf::Vector2f randLocation1;
    sf::Vector2f randLocation2;
    sf::Vector2f randLocation3;
    sf::Vector2f randLocation4;

    bool direction;
    bool jumping;
    bool blocking;
    bool attacking;
    bool flipFireBallVel;
    bool attAnimation;
    bool takeDamage;
    bool freezeInput;
    bool showHealth;
    bool showAmmo;
    bool showFrag;

    sf::Vector2f jumpVector;
    sf::Vector2f gravity;
    sf::Vector2f ammoVel;
    int ammoX;
    int ammoY;

    int speed;
    int jumpSpeed;
    int maxHealth;
    int health;
    int ammoCount;
    int fragmentCount;

    sf::Text healthText;
    sf::Text ammoText;
    sf::Text fragText;
    sf::Font font;

    //Include these managers so player can access functions in respective classes
    FireBallManager ammoManager;
    PickupManager pickupManager;
    PortalManager portalManager;
};

