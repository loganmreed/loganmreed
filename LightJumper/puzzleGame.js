const character = document.getElementById('character');
const platform = document.getElementById('platform');
const door = document.getElementById('door');
const key = document.getElementById('key');
const keytwo = document.getElementById('keytwo');

let isCollidingWithPlatformBottom = false;

const gravity = 9.8; 
const floorY = platform.offsetTop;
let MAX_BOXES_PER_COLUMN = 0;
let BOX_LEVEL_LIMIT = 0;
let BOX_LEVEL_LIMIT_SHOW = 0;
let NeedWall = false;
let Needskyplatform = false;
let Needkeytwo = false;
let interval;

const gridSizeX = 74;
const gridSizeY = 72;
const boxWidth = 70; 
const boxHeight = 70;

const marginBottomPercentage = 0.07;
const screenHeight = window.innerHeight;
const marginBottom = screenHeight * marginBottomPercentage;

const marginRightPercentage = 0.10;
const screenWidth = window.innerWidth;
const marginRight = screenWidth * marginRightPercentage;

const availableWidth = screenWidth - marginRight;

const availableHeight = screenHeight - marginBottom;
const rows = Math.floor(availableHeight / boxHeight);
const columns = Math.floor(screenWidth / gridSizeX);

const occupied = Array(columns).fill(0);
const boxes = [];
let skyPlatforms = []; 

let keys = {};
let characterVelocity = { x: 0, y: 0 };
let characterMass = 10;
let onGround = true;
let isStandingOnSomething = true;
let LockedDoor = true;
let Level = 1;

let speed = 10;
let airControlFactor = 0.5;

document.addEventListener('keydown', (e) => (keys[e.code] = true));
document.addEventListener('keyup', (e) => (keys[e.code] = false));

window.addEventListener('resize', adjustSpeed);

function gameLoop() {
    checkCollisions();
    handleCharacterMovement();
    checkCollisions();
    applyPhysics();
    updateCharacterPosition();
    requestAnimationFrame(gameLoop);
    door.setAttribute('data-Islocked', LockedDoor);
}

function handleCharacterMovement() {
  if (keys['ArrowLeft']) {
    characterVelocity.x = onGround ? -speed : -speed * airControlFactor;
    character.classList.add('walking-x');
    character.style.transform = 'rotateY(70deg)';
  } else if (keys['ArrowRight']) {
    characterVelocity.x = onGround ? speed : speed * airControlFactor;
    character.classList.add('walking-x');
    character.style.transform = 'rotateY(-70deg)';
  } else {
    characterVelocity.x = 0;
    character.classList.remove('walking-x');
    character.style.transform = 'rotateY(45deg)';
  }
}

function applyPhysics() {
    if (!isStandingOnSomething){
    characterVelocity.y += Math.floor(gravity * characterMass * 0.016);
    }
}

function updateCharacterPosition() {
    const nextPosition = {
        x: character.offsetLeft + characterVelocity.x,
        y: character.offsetTop + characterVelocity.y,
    };

    if (nextPosition.x < 0) {
        nextPosition.x = 0;
        characterVelocity.x = 0;
    }

    if (nextPosition.x + character.offsetWidth > screenWidth) {
        nextPosition.x = screenWidth - character.offsetWidth;
        characterVelocity.x = 0;
    }

    if (nextPosition.y < 0) {
        nextPosition.y = 0;
        characterVelocity.y = 0;
    }

    if (nextPosition.y + character.offsetHeight > floorY) {
        nextPosition.y = floorY - character.offsetHeight;
        characterVelocity.y = 0;
        onGround = true;
    }

    character.style.left = `${nextPosition.x}px`;
    character.style.top = `${nextPosition.y}px`;
}

function adjustSpeed() {
    speed = window.innerWidth / 200;
  }  

const MAX_CLIMB_HEIGHT = character.offsetHeight / 2;

function checkCollisions() {
    const characterBounds = character.getBoundingClientRect();
    const { bottom: characterBottom, top: characterTop, left: characterLeft, right: characterRight } = characterBounds;

    let standingOnSomething = false;

    const keyBounds = key.getBoundingClientRect();
    if (characterRight > keyBounds.left && characterLeft < keyBounds.right && characterBottom > keyBounds.top && characterTop < keyBounds.bottom) {
        key.style.backgroundColor = 'blue';
        LockedDoor = false;
        door.innerText = 'Open';
    }

    if (Needkeytwo) {
        const keytwoBounds = keytwo.getBoundingClientRect();
        if (characterRight > keytwoBounds.left && characterLeft < keytwoBounds.right && characterBottom > keytwoBounds.top && characterTop < keytwoBounds.bottom) {
            keytwo.style.backgroundColor = 'blue';
            LockedDoor = false;
            door.innerText = 'Open';
        }
    }

    if (NeedWall) {
        const wallBounds = wall.getBoundingClientRect();
        if (characterRight > wallBounds.left && characterLeft < wallBounds.right && characterBottom > wallBounds.top && characterTop < wallBounds.bottom) {
            if (characterRight > wallBounds.left && characterLeft < wallBounds.left) characterVelocity.x = -10; // Stop rightward
            else if (characterLeft < wallBounds.right && characterRight > wallBounds.right) characterVelocity.x = 10; // Stop leftward

            if (characterBottom >= wallBounds.top && characterBottom <= wallBounds.top + 5) {
                onGround = true;
                characterVelocity.y = 0;
                character.style.top = `${wallBounds.top - character.offsetHeight}px`;
            }
        }
    }

    if (Needskyplatform) {
        const skyplatformBounds = skyplatform.getBoundingClientRect();
        if (characterRight > skyplatformBounds.left && characterLeft < skyplatformBounds.right && characterBottom > skyplatformBounds.top && characterTop < skyplatformBounds.bottom) {
            // Horizontal collision
            if (characterRight > skyplatformBounds.left && characterLeft < skyplatformBounds.left) {
                characterVelocity.x = -1; // Stop rightward
            }
            else if (characterLeft < skyplatformBounds.right && characterRight > skyplatformBounds.right) {
                characterVelocity.x = 1; // Stop leftward
            }
            if (characterBottom >= skyplatformBounds.top && characterBottom <= skyplatformBounds.top + 5) {
                onGround = true;
                characterVelocity.y = 0;
                character.style.top = `${skyplatformBounds.top - character.offsetHeight}px`;
            }
 
            if (characterTop < skyplatformBounds.bottom && characterBottom > skyplatformBounds.bottom) {
                characterVelocity.y = 0; // Stop downward movement
                characterVelocity.x = -1;
                if (!isCollidingWithPlatformBottom) {
                    isCollidingWithPlatformBottom = true; 
                }
            }
        }
        if (isCollidingWithPlatformBottom && characterTop >= skyplatformBounds.bottom) {
            isCollidingWithPlatformBottom = false; // Reset the flag if no longer colliding
            skyplatform.style.backgroundColor = '#808080'; // Reset platform color
        }
    }
    const doorBounds = door.getBoundingClientRect();
    if (characterRight > doorBounds.left && characterLeft < doorBounds.right && characterBottom > doorBounds.top && characterTop < doorBounds.bottom && !LockedDoor) {
        Level++;
        characterVelocity = { x: 0, y: 0 };
        // Level-specific changes
        if (Level === 2) {
            textContainer.innerText = `Level: ${Level}\nUse the Left mouse button to create a stair case.`;
            NeedWall = false;
            Needskyplatform = false;
            NextLevel(level2Config);
        } else if (Level === 3) {
            textContainer.innerText = `Level: ${Level}\nSome levels have obstacles.`;
            NextLevel(level3Config);
            NeedWall = true;
            wall.style.display = 'block';
        } else if (Level === 4) {
            textContainer.innerText = `Level: ${Level}\nGood Luck.`;
            NextLevel(level4Config);
            NeedWall = true;
            Needskyplatform = true;
            skyplatform.style.display = 'block';
            skyplatform.style.backgroundColor = '#808080';
            wall.style.height = '36%';
        } else if (Level === 5) {
            textContainer.innerText = `Level: ${Level}\n`;
            NextLevel(level5Config);
            wall.style.display = 'block';
            skyplatform.style.display = 'block';
            skyplatform.style.height = '36%';
            skyplatform.style.width = '76px';
            skyplatform.style.left = '61%';
            skyplatform.style.bottom = '7%';
            key.style.right = '39.2%';
        } else if (Level === 6) {
            textContainer.innerText = `Level: ${Level}`;
            NextLevel(level6Config);
            wall.style.display = 'block';
            NeedWall = true;
            Needskyplatform = false;
            skyplatform.style.display = 'none';
            skyplatform.style.height = '36%';
            skyplatform.style.width = '76px';
            skyplatform.style.left = '61%';
            skyplatform.style.bottom = '7%';
            wall.style.height='36%';
            key.style.right = '39.2%';
            door.style.right = '90%';
        } else if (Level === 7) {
            textContainer.innerText = `Level: ${Level}\nSome`;
            NextLevel(level7Config);
            wall.style.display = 'block';
            wall.style.height = '40%';
            wall.style.left = '36.5%';
            skyplatform.style.display = 'block';
            skyplatform.style.height = '55%';
            skyplatform.style.width = '76px';
            skyplatform.style.left = '62%';
            skyplatform.style.bottom = '7%';
            key.style.right = '50%';
            Needkeytwo = true;
            keytwo.style.display = 'block';
            createSkyPlatform(10,22,7,40)
            createSkyPlatform(13,6,47,36.5)
            createSkyPlatform(4,35,67,33)
            createSkyPlatform(4,35,67,49)
            door.style.right = '0%';
        }
    }
    const topBoxes = {};

    // Find the top box in each column
    boxes.forEach((box) => {
        const boxColumn = box.getAttribute('data-column');
        const boxBounds = box.getBoundingClientRect();
        if (!topBoxes[boxColumn] || boxBounds.top < topBoxes[boxColumn].getBoundingClientRect().top) {
            topBoxes[boxColumn] = box;
        }
    });

    boxes.forEach((box) => {
        const boxColumn = box.getAttribute('data-column');
        const topBox = topBoxes[boxColumn];
        const boxBounds = box.getBoundingClientRect();

        if (box !== topBox) {
            box.setAttribute('data-isClimbable', false);
            box.classList.add('non-climbable');

            if (characterBounds.right > boxBounds.left && characterBounds.left < boxBounds.right && characterBounds.bottom > boxBounds.top && characterBounds.top < boxBounds.bottom) {
                if (characterBounds.right > boxBounds.left && characterBounds.left < boxBounds.left) characterVelocity.x = -1; // Stop leftward -1
                else if (characterBounds.left < boxBounds.right && characterBounds.right > boxBounds.right) characterVelocity.x = 1; // Stop rightward 1
            }
        } else if (box == topBox && isCollidingWithPlatformBottom){
            if (characterBounds.right > boxBounds.left && characterBounds.left < boxBounds.right && characterBounds.bottom > boxBounds.top && characterBounds.top < boxBounds.bottom) {
                if (characterBounds.right > boxBounds.left && characterBounds.left < boxBounds.left) characterVelocity.x = -1; // Stop leftward -1
                else if (characterBounds.left < boxBounds.right && characterBounds.right > boxBounds.right) characterVelocity.x = 1; // Stop rightward 1
            }
        }else {
            // Climbable top box logic
            const isClimbable = characterTop <= boxBounds.top && boxBounds.top - characterTop <= MAX_CLIMB_HEIGHT;
            box.setAttribute('data-isClimbable', isClimbable);
            box.classList.toggle('non-climbable', !isClimbable);

            if (characterBottom >= boxBounds.top && characterBottom <= boxBounds.bottom + 5 && characterRight > boxBounds.left && characterLeft < boxBounds.right) {
                standingOnSomething = true;
                characterVelocity.y = 0;
                onGround = true;
                character.style.top = `${Math.floor(boxBounds.top - character.offsetHeight)}px`;
            }
        }
    });

    isStandingOnSomething = standingOnSomething;

    // Fall if not standing on anything
    if (!standingOnSomething) onGround = false;
}

function getCharacterColumns() {
    const leftColumn = Math.floor(character.offsetLeft / gridSizeX);
    const rightColumn = Math.floor((character.offsetLeft + character.offsetWidth) / gridSizeX);
    return [leftColumn, rightColumn]; // Return columns the character spans
}

document.body.addEventListener('click', function (event) {
    const column = Math.floor(event.pageX / gridSizeX);
    const [leftColumn, rightColumn] = getCharacterColumns();
    if (column >= leftColumn && column <= rightColumn) {
        const message = document.createElement('div');
        message.classList.add('message');
        message.textContent = `Cannot place box; character there.`;
        message.style.position = 'absolute';
        message.style.left = `${event.pageX}px`;
        message.style.top = `${event.pageY - 30}px`;
        document.body.appendChild(message);

        setTimeout(() => {
            message.style.transition = 'opacity 5s ease-out';
            message.style.opacity = 0;
        }, 0);

        setTimeout(() => {
            message.remove();
        }, 6000);

        return;
    }

    // Prevent placing a box outside available width
    const x = column * gridSizeX;
    if (x + gridSizeX > availableWidth) {
        return;
    }

    const row = occupied[column];

    // Prevent adding more boxes if the column is full
    if (row >= MAX_BOXES_PER_COLUMN) {
        console.log(`Column ${column} is full`);
        return;
    }

    // Place a new box if there's space
    if (row < rows) {
        const box = document.createElement('div');
        box.classList.add('box');
        box.style.left = `${x}px`;
        box.style.top = `${screenHeight - marginBottom - (row + 1) * gridSizeY}px`;

        box.setAttribute('data-column', column);

        document.body.appendChild(box);

        occupied[column]++;
        boxes.push(box);
    }
});

function NextLevel(levelConfig) {
    const keyX = window.innerWidth * levelConfig.keyXPercentage;
    const keyY = window.innerHeight * levelConfig.keyYPercentage;
    key.style.left = `${keyX}px`;
    key.style.top = `${keyY}px`;

    // Lock the door
    LockedDoor = true;
    door.innerText = 'Locked';

    // Set character position
    const characterX = window.innerWidth * levelConfig.characterXPercentage;
    const characterY = window.innerHeight * levelConfig.characterYPercentage;
    character.style.left = `${characterX}px`;
    character.style.top = `${characterY}px`;

    MAX_BOXES_PER_COLUMN = levelConfig.maxBoxesPerColumn;

    // Set key color
    key.style.backgroundColor = levelConfig.keyColor;

    textLevelDetails.innerText = `Max Build Height: ${MAX_BOXES_PER_COLUMN}\nRestart Level`;
    clearBoxes();
}
function clearBoxes() {
    boxes.forEach(box => box.remove()); 
    boxes.length = 0; 
    occupied.fill(0); 

    console.log("Boxes cleared. Occupied state reset.");
}

const level1Config = {
    keyXPercentage: 0.5, 
    keyYPercentage: 0.80, 
    characterXPercentage: 0.2, 
    characterYPercentage: 0.70, 
    maxBoxesPerColumn: 0, 
    keyColor: '#ff6600', 
};

const level2Config = {
    keyXPercentage: 0.5,
    keyYPercentage: 0.55,
    characterXPercentage: 0.2,
    characterYPercentage: 0.70,
    maxBoxesPerColumn: 2,
    keyColor: '#ffd700',
};

const level3Config = {
    keyXPercentage: 0.6,
    keyYPercentage: 0.80,
    characterXPercentage: 0.2,
    characterYPercentage: 0.70,
    maxBoxesPerColumn: 5,
    keyColor: '#ffd700',
};

const level4Config = {
    keyXPercentage: 0.6,
    keyYPercentage: 0.80,
    characterXPercentage: 0.2,
    characterYPercentage: 0.70,
    maxBoxesPerColumn: 5,
    keyColor: '#ffd700',
};

const level5Config = {
    keyXPercentage: 0.508,
    keyYPercentage: 0.80,
    characterXPercentage: 0.2,
    characterYPercentage: 0.70,
    maxBoxesPerColumn: 5,
    keyColor: '#ffd700',
};

const level6Config = {
    keyXPercentage: 0.508,
    keyYPercentage: 0.80,
    characterXPercentage: 0.2,
    characterYPercentage: 0.70,
    maxBoxesPerColumn: 10,
    keyColor: '#ffd700',
};

const level7Config = {
    keyXPercentage: 0.38,
    keyYPercentage: 0.19,
    characterXPercentage: 0.2,
    characterYPercentage: 0.70,
    maxBoxesPerColumn: 11,
    keyColor: '#ffd700',
};

// Add click event listener to restart
document.getElementById('textLevelDetails').addEventListener('click', function(event) {
    event.stopPropagation(); // Prevent event bubbling
    restart(); // Restart the game
  });  

function restart() {
    let Levelrestart = Level;
    characterVelocity = { x: 0, y: 0 };
    console.log(`Level ${Level} and restart level ${Levelrestart}`);
    textContainer.innerText = `Level: ${Level}\nUse the arrow keys to move left and right.`;
    if (Levelrestart === 1){
        NeedWall = false;
        Needskyplatform = false;
        NextLevel(level1Config);
    }else if(Levelrestart === 2){
        textContainer.innerText = `Level: ${Level}\nUse the Left mouse button to create a stair case.`;
        NeedWall = false;
        Needskyplatform = false;
        NextLevel(level2Config);
    }else if (Levelrestart === 3){
        textContainer.innerText = `Level: ${Level}\nSome levels have a obstacles.`;
        NeedWall = true;
        Needskyplatform = false;
        NextLevel(level3Config);
        wall.style.display = 'block';
    }else if (Levelrestart === 4){
        textContainer.innerText = `Level: ${Level}\nGood Luck.`;
        NeedWall = true;
        Needskyplatform = true;
        NextLevel(level4Config);
        wall.style.display = 'block';
        skyplatform.style.display = 'block';
        wall.style.height='36%';
        skyplatform.style.backgroundColor = '#808080';
    }else if (Level === 5){
        textContainer.innerText = `Level: ${Level}`;
        NextLevel(level5Config);
        wall.style.display = 'block';
        NeedWall = true;
        Needskyplatform = true;
        skyplatform.style.display = 'block';
        skyplatform.style.height = '36%';
        skyplatform.style.width = '76px';
        skyplatform.style.left = '61%';
        skyplatform.style.bottom = '7%';
        wall.style.height='36%';
        key.style.right = '50.8%';
    }else if (Level === 6){
        textContainer.innerText = `Level: ${Level}`;
        NextLevel(level6Config);
        wall.style.display = 'block';
        NeedWall = true;
        Needskyplatform = false;
        skyplatform.style.display = 'none';
        skyplatform.style.height = '36%';
        skyplatform.style.width = '76px';
        skyplatform.style.left = '61%';
        skyplatform.style.bottom = '7%';
        wall.style.height='36%';
        key.style.right = '39.2%';
        door.style.right = '90%';
    }else if (Level === 7){
        textContainer.innerText = `Level: ${Level}\nSome`;
        NextLevel(level7Config);
        wall.style.display = 'block';
        NeedWall = true;
        Needskyplatform = true;
        skyplatform.style.display = 'block';
        skyplatform.style.height = '36%';
        skyplatform.style.width = '76px';
        skyplatform.style.left = '61%';
        skyplatform.style.bottom = '7%';
        door.style.right = '0%';
        wall.style.height='36%';
        key.style.right = '50.8%';
        Needkeytwo = true;
        keytwo.style.display = 'block';
    }
}

function createSkyPlatform(widthPercentage, heightPercentage, bottomPercentage, leftPercentage) {
    // Create a new sky platform element
    let skyplatform = document.createElement('div');
    
    // Set the styles for the platform using percentages
    skyplatform.style.height = heightPercentage + '%';
    skyplatform.style.width = widthPercentage + '%';
    skyplatform.style.position = 'absolute'; // Ensure the platform is positioned correctly
    skyplatform.style.bottom = bottomPercentage + '%';
    skyplatform.style.left = leftPercentage + '%';
    skyplatform.style.backgroundColor = '#00ff00'; // Set a visible color
    skyplatform.style.zIndex = 10; // Ensure it is above other elements

    // Optionally, add a class for styling or identification
    skyplatform.classList.add('skyplatform');

    // Add the platform to the game container
    document.querySelector('.game-container').appendChild(skyplatform);

    // Add the created sky platform to the array
    skyPlatforms.push(skyplatform);
}


// Function to remove all sky platforms
function destroySkyPlatforms() {
    // Loop through the skyPlatforms array and remove each from the DOM
    skyPlatforms.forEach(platform => {
        platform.remove();
    });
    
    // Clear the array
    skyPlatforms = [];
}

// Prevent right-click on the game container
const gameContainer = document.querySelector('.game-container');
gameContainer.addEventListener('contextmenu', function (event) {
    event.preventDefault(); // Disable context menu
});

// Alternatively, prevent right-clicking on the body
document.body.addEventListener('contextmenu', function (event) {
    event.preventDefault(); // Disable context menu
});

// Set up the first level
NextLevel(level1Config);
textContainer.innerText = `Level: ${Level}\nUse arrow keys to move.`;
// Hide the second key
keytwo.style.display = 'none';

// Start the game loop
gameLoop();
