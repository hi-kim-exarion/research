# 워크스페이스 가이드: 연구 및 개발 환경

이 워크스페이스는 **연구(이론)**, **프로토타이핑(Python)**, **개발(C++)**을 하나의 통합된 환경에서 수행할 수 있도록 구성되었습니다. 지식 관리를 위해 **Foam**을 사용하고, 빌드 시스템으로 **CMake/Ninja**를 사용합니다.

## 1. 디렉토리 구조

- **`docs/`**: 지식 베이스 (Foam 저장소)
    - `00_Inbox/`: 빠른 메모, 날것의 아이디어, 읽어야 할 논문 등
    - `10_Theory/`: 이론적 배경, 수식 유도, 논문 리뷰
    - `20_Design/`: 소프트웨어 아키텍처, UML 다이어그램, 설계 문서
    - `30_DevLog/`: 일일 개발 일지 및 실험 기록
    - `templates/`: 표준화된 문서 템플릿
- **`prototypes/`**: 알고리즘 검증을 위한 Python 스크립트 및 Jupyter Notebook
- **`src/`**: C++ 소스 코드 (현재 루트에 위치, 필요시 `src/`로 정리 가능)
- **`build/`**: CMake 빌드 결과물

## 2. 워크플로우 가이드

### 1단계: 연구 및 이론 (Research & Theory)
1. `docs/10_Theory/`에 새로운 노트를 생성하여 개념을 정리합니다.
2. **LaTeX**를 사용하여 수식을 작성합니다:
   $$ \nabla^2 p - \frac{1}{c^2} \frac{\partial^2 p}{\partial t^2} = 0 $$
3. 위키 링크(`[[개념 이름]]`)를 사용하여 관련 개념들을 연결합니다.

### 2단계: 프로토타이핑 (Prototyping with Python)
1. `prototypes/` 폴더에 Jupyter Notebook을 생성합니다.
2. 수식을 코드로 구현하여 로직을 검증하고 참조 데이터를 생성합니다.
3. 이론 노트에 노트북 링크를 추가합니다: `[프로토타입 링크](../../prototypes/my_experiment.ipynb)`.

### 3단계: 구현 (Implementation with C++)
1. 프로젝트 루트(또는 `src/`)에 C++ 코드를 작성합니다.
2. **알고리즘 명세서 템플릿**(`docs/templates/Algorithm_Spec.md`)을 사용하여 구현 세부 사항을 문서화하고, 이론 및 프로토타입 문서와 연결합니다.

### 4단계: 빌드 및 디버깅 (Build & Debug)
- **빌드**: `Ctrl+Shift+B` (Ninja 빌드 실행)
- **디버깅**: `F5` (LLDB로 `AntigravityTest.exe` 디버깅 시작)
- **클린 빌드**: `build/` 폴더를 삭제하고 CMake를 다시 실행합니다.

## 3. 유용한 기능

- **Foam 그래프**: `Ctrl+Shift+P` -> `Foam: Show Graph`를 실행하여 노트 간의 연결 관계를 시각화합니다.
- **데일리 노트**: `Ctrl+Shift+P` -> `Foam: Open Daily Note`를 실행하여 오늘의 개발 진행 상황을 `docs/30_DevLog/`에 기록합니다.
- **이미지 붙여넣기**: 이미지를 복사한 후 `Ctrl+Alt+V` (확장 프로그램 필요)를 눌러 마크다운 파일에 바로 붙여넣습니다.
- **Draw.io**: `.drawio` 파일을 생성하여 VS Code 내에서 다이어그램을 직접 그립니다.

## 4. 추천 확장 프로그램
(전체 목록은 `.vscode/extensions.json` 참조)
- **Foam**: 위키 링크 및 그래프 뷰 지원
- **Markdown All in One**: 단축키 및 수식 지원
- **Jupyter**: Python 노트북 실행 지원
- **CMake Tools**: C++ 빌드 구성 지원
